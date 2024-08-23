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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include <stdint.h>

/* Add Your Declarations and Function Comments here */ 
 
 /**
 * @brief This method prints array statistics.
 *
 * The statistics printed are median, mean, maximum, and minimum for a given array.
 *
 * @param[in] array_p - pointer to the array for which the statistics need to be printed
 */
 void print_statistics(unsigned char* array_p, uint8_t array_length);
 
 /**
 * @brief This method prints the entire contents of an array.
 *
 * @param[in] array_p - pointer to the array 
 *
 */
 void print_array(unsigned char* array_p, uint8_t array_length);
 
 /**
 * @brief This method finds the median value in the array.
 *
 * @param[in] array_p - pointer to the array
 *
 * @return double - the median
 */
 double find_median(unsigned char* array_p, uint8_t array_length);
 
 /**
 * @brief This method finds the mean of all values in the array.
 *
 * @param[in] array_p - pointer to the array
 *
 * @return double - the mean
 */
 double find_mean(unsigned char* array_p, uint8_t array_length);
 
 /**
 * @brief This method finds the minimum value in the array.
 *
 * @param[in] array_p - pointer to the array
 *
 * @return uint8_t - the minimum value in the array
 */
 unsigned char find_minimum(unsigned char* array_p, uint8_t array_length);
 
 /**
 * @brief This method finds the maximum value in the array.
 *
 * @param[in] array_p - pointer to the array
 *
 * @return uint8_t - the maximum value in the array
 */
 unsigned char find_maximum(unsigned char* array_p, uint8_t array_length);
 
 /**
 * @brief This method sorts the array in a descending order.
 *
 * @param[in] array_p - pointer to the array
 */
 void sort_array(unsigned char* array_p, uint8_t array_length);

#endif /* __STATS_H__ */
