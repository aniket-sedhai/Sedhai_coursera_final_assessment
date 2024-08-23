/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
  int16_t index = 0;
  int16_t gap = 0;
  uint16_t i = 0;
  
  if ((src == NULL) || (dst == NULL))
  {
  	return NULL;
  }
  
  if (length < 1)
  {
  	return dst;
  }
  
  if (dst == src)
  {
    return dst;
  }
  
  /*check for overlap*/
  gap = dst - src;
  
  /*there is an overlap and destination pointer is at higher address than src pointer*/
  if ((gap > 0) && (gap < length))
  {
    for (i = length - gap; i < (length + gap); ++i)
    {
      *(dst + i) = *(src++);
    }
  }
  else if ((gap > -1*length) && (gap < 0))
  {
    for (i = 0; i < (-1*gap); ++i)
    {
      *(dst++) = *(src++);
    }
  }
  else
  {
    while (index < length)
    {
      *(dst++) = *(src++);
      index++;
    }
  }
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
  int16_t index = 0;
  
  if ((src == NULL) || (dst == NULL))
  {
  	return NULL;
  }
  
  if (length < 1)
  {
  	return dst;
  }
  
  if (dst == src)
  {
    return dst;
  }
  
  while (index < length)
  {
    *(dst++) = *(src++);
    index++;
  }
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
	uint8_t index = 0;
	
	if (src == NULL)
  {
  	return NULL;
  }
  
  if (length < 1)
  {
  	return src;
  }
  
  while (index < length)
  {
  	*src++ = value;
  	++index;
  }
  
  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
	uint8_t index = 0;
	
	if (src == NULL)
  {
  	return NULL;
  }
  
  if (length < 1)
  {
  	return src;
  }
  
  while (index < length)
  {
  	*src++ = 0;
  	++index;
  }
  
  return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
	uint8_t temp_val;
	uint8_t index = 0;
	uint8_t* current_val_p = src;
	
	if (src == NULL)
  {
  	return NULL;
  }
  
  if (length < 1)
  {
  	return src;
  }
  
  for (index = 0; index < length / 2; ++index)
  {
  	temp_val = *current_val_p;
  	*current_val_p = *(src + (uint8_t)(length - index));
  	*(current_val_p + (uint8_t)(length - index)) = temp_val;
	}
}

int32_t * reserve_words(size_t length)
{
	return (uint32_t*) malloc(length * sizeof(uint32_t));
}

void free_words(int32_t * src)
{
	if (src != NULL)
	{
		free(src);
	}
}
