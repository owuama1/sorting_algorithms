#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two sorted sub-arrays into one sorted array
 * @array: Original array containing both sub-arrays
 * @size: Total size of the array
 * @left: Pointer to the beginning of the left sub-array
 * @right: Pointer to the beginning of the right sub-array
 * @temp: Temporary array to store merged result
 */
void merge(int *array, size_t size, int *left, int *right, int *temp)
{
	int *temp_start = temp;
	int *left_end = right; /* end of left array */
	int *right_end = array + size; /* end of right array */

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_end - left);
	printf("[right]: ");
	print_array(right, right_end - right);

	/* Merge the two halves into temp array */
	while (left < left_end && right < right_end)
	{
		if (*left <= *right)
			*temp++ = *left++;
		else
			*temp++ = *right++;
	}

	/* Copy remaining elements from left sub-array (if any) */
	while (left < left_end)
		*temp++ = *left++;

	/* Copy remaining elements from right sub-array (if any) */
	while (right < right_end)
		*temp++ = *right++;

	/* Copy sorted elements from temp back to original array */
	temp = temp_start;
	while (array < right_end)
		*array++ = *temp++;

	printf("[Done]: ");
	print_array(array - size, size);
}

/**
 * merge_sort_recursive - Recursive funct to sort the arr using Merge SA
 * @array: Array to be sorted
 * @size: Size of the array
 * @temp: Temporary array for merging
 */
void merge_sort_recursive(int *array, size_t size, int *temp)
{
	/* Divide the array into two halves */
	int *mid = array + size / 2;

	if (size < 2)
		return;


	/* Recursive calls to sort the two halves */
	merge_sort_recursive(array, mid - array, temp);
	merge_sort_recursive(mid, size - (mid - array), temp);

	/* Merge the two sorted halves */
	merge(array, size, array, mid, temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge SA
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	/* Allocate a temporary array for merging */
	int *temp = malloc(size * sizeof(int));

	if (temp == NULL)
	{
		fprintf(stderr, "Failed to allocate memory\n");
		return;
	}

	/* Call the recursive merge sort function */
	merge_sort_recursive(array, size, temp);

	/* Free the temporary array */
	free(temp);
}
