#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * getMax - Utility function to get the maximum element in an array
 * @array: Array of integers
 * @size: Size of the array
 * Return: The maximum element in the array
 */
static int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countingSort - A function to sort the array using Counting Sort based on
 * a significant digit represented by exp.
 * @array: Array of integers
 * @size: Size of the array
 * @exp: The significant digit, i.e., power of 10
 */
static void countingSort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;

	if (output == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < size; ++i)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; ++i)
		count[i] += count[i - 1];

	for (i = size - 1; i < size; --i)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; ++i)
		array[i] = output[i];

	print_array(array, size);

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 * algorithm (LSD - Least Significant Digit)
 * @array: Array of integers
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
		countingSort(array, size, exp);
}
