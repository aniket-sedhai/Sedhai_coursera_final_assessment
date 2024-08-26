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
 * @file stats.c 
 * @brief This is the implementation file for stats.h
 *
 * This file implements the functions declared in stats.h. It has functions
 * to print an array containing unsigned chars, sort the array, find
 * statistics like mean, medium, maximum, and, minimum values.
 *
 * @author Aniket Sedhai
 * @date 08/14/2024
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/*********************************************************************************************************************/

void print_array(uint8_t* array_p, uint8_t array_length)
{

#ifdef VERBOSE
  /*check for null pointer*/
  if (array_p == NULL)
  {
    PRINTF("null pointer detected\n");
    return;
  }

  if (array_length < 1)
  {
    PRINTF("invalid input array size\n");
    return;
  }

  for (uint8_t i = 0; i < array_length; ++i)
  {
    PRINTF("array[%u](0x%x): %u\n",i, array_p + i, *(array_p + i));
  }

  PRINTF("\n");
#endif /*VERBOSE*/
}

/*********************************************************************************************************************/

void print_statistics(unsigned char* array_p, uint8_t array_length)
{
  PRINTF("==== Statistics ====\n");
  PRINTF("Minimum: %d\n", find_minimum(array_p, array_length));
  PRINTF("Maximum: %d\n", find_maximum(array_p, array_length));
  PRINTF("Mean: %.3f\n", find_mean(array_p, array_length));
  PRINTF("Median: %.3f\n", find_median(array_p, array_length));
  PRINTF("====================\n");
}

/*********************************************************************************************************************/

double find_median(unsigned char* array_p, uint8_t array_length)
{
  /*check for null pointer*/
  if (array_p == NULL)
  {
    printf("null pointer detected\n");
    return -1;
  }

  if (array_length < 1)
  {
    printf("invalid input array size\n");
    return -1;
  }

  /*sort the array*/
  sort_array(array_p, array_length);

  /*find the median*/
  if (array_length % 2 == 0)
  {
     return (double)(array_p[(array_length / 2) - 1] + array_p[(array_length / 2)]) / 2.0;
  }
  else
  {
    return (double) array_p[(array_length + 1) / 2];
  }

  return -1;
}
 
/*********************************************************************************************************************/

void merge(unsigned char* array_p, uint8_t left_index, uint8_t mid_index, uint8_t right_index)
{
  uint8_t i, j, k;
  uint8_t left_array_size = mid_index - left_index + 1;
  uint8_t right_array_size = right_index - mid_index;

  //create temp arrays
  unsigned char left_array[left_array_size], right_array[right_array_size];

  for (i = 0; i < left_array_size; ++i)
  {
    left_array[i] = array_p[left_index + i];
  }

  for (j = 0; j < right_array_size; ++j)
  {
    right_array[j] = array_p[mid_index + 1 + j];
  }

  //Merge the temp arrays back
  //reset the index of the first and the second sub array
  i = 0; j = 0;

  //initial index of the merged subarray
  k = left_index;

  while ((i < left_array_size) && (j < right_array_size))
  {
    if (left_array[i] >= right_array[j])
    {
      array_p[k] = left_array[i];
      ++i;
    }
    else
    {
      array_p[k] = right_array[j];
      ++j;
    }

    ++k;
  }

  //copy the remaining elements of left array if any
  while (i < left_array_size)
  {
    array_p[k] = left_array[i];
    ++i;
    ++k;
  }

  //copy the remaining elements of right array if any
  while (j < right_array_size)
  {
    array_p[k] = right_array[j];
    ++j;
    ++k;
  }
}

/*********************************************************************************************************************/

void merge_sort(unsigned char* array_p, uint8_t left_index, uint8_t right_index)
{
  if (left_index < right_index)
  {
    uint8_t mid_index = left_index + (right_index - left_index) / 2;

    merge_sort(array_p, left_index, mid_index);
    merge_sort(array_p, mid_index + 1, right_index);

    merge(array_p, left_index, mid_index, right_index);
  }
}

/*********************************************************************************************************************/

void sort_array(unsigned char* array_p, uint8_t array_length)
{
  merge_sort(array_p, 0, array_length - 1);
}

/*********************************************************************************************************************/

double find_mean(unsigned char* array_p, uint8_t array_length)
{
  uint32_t sum = 0;

  for (uint8_t i = 0; i < array_length; ++i)
  {
    sum += array_p[i];
  }

  return  (double) sum / (double) array_length;
}

/*********************************************************************************************************************/

unsigned char find_minimum(unsigned char* array_p, uint8_t array_length)
{
  sort_array(array_p, array_length);

  return (array_p[array_length - 1]);
}

/*********************************************************************************************************************/

unsigned char find_maximum(unsigned char* array_p, uint8_t array_length)
{
  sort_array(array_p, array_length);

  return (array_p[0]);
}

/*********************************************************************************************************************/
