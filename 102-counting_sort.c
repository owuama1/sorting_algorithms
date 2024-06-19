#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an arr of ints in ascending order using CSA
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max_value = 0;
	int *counter, *tmp, index;
	size_t i;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	counter = (int *)calloc(max_value + 1, sizeof(int));
	if (counter == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}
	tmp = (int *)malloc(size * sizeof(int));
	if (tmp == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free(counter);
		return;
	}
	for (i = 0; i < size; i++)
		counter[array[i]]++;
	for (index = 1; index <= max_value; index++)
		counter[index] += counter[index - 1];

	print_array(counter, max_value + 1);
	for (i = 0; i < size; ++i)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = tmp[i];

	free(tmp);
	free(counter);
}
