#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array of ints in ascending order using Bubble Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n = size;
	int temp;
	int swapped;

	if (size < 2)
		return;

	do {
		swapped = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		n--;
	} while (swapped);
}
