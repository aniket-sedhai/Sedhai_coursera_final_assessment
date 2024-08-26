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
#include <stdlib.h>

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
  uint8_t *lasts;
  uint8_t *lastd;
  
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
  
  // If the destination memory address is less than the source address
  if (dst < src)
  {
    while (length--)
    {
    	*dst++= *src++;
    }
  }
  // When destination memory address is greater than source address
  else
  {
    lasts = src + (length-1);    // gets the address of the last source byte
    lastd = dst + (length-1);    // gets the address of the last destination byte
    while (length--)
    {
      *lastd-- = *lasts--;
    }
  }
  return dst;
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
  
  return dst;
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
  	*current_val_p = *(src + (uint8_t)(length - index - 1));
  	*(src + (uint8_t)(length - index - 1)) = temp_val;
  	current_val_p++;
	}
	
	return src;
}

int32_t * reserve_words(size_t length)
{
	return (int32_t*) malloc(length * sizeof(int32_t));
}

void free_words(uint32_t * src)
{
	if (src != NULL)
	{
		free((void*)src);
	}
}
