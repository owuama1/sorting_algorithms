#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sift_down - Performs the sift-down operation to maintain heap property
 * @array: Array to be sorted
 * @start: Index of the root of the heap
 * @end: Index of the last element in the heap
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;

	while (root * 2 + 1 <= end)
	{
		size_t child = root * 2 + 1;
		size_t swap = root;

		/* Find the largest child */
		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			/* Swap root with the largest child */
			int temp = array[root];

			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heapify - Converts an array into a max heap
 * @array: Array to be heapified
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
	size_t start;
	/* Build heap (rearrange array) */
	for (start = size / 2 - 1; start > 0; start--)
		sift_down(array, start, size - 1, size);
	sift_down(array, 0, size - 1, size);
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap SA
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	/* Build max heap */
	heapify(array, size);

	/* One by one extract elements */
	for (end = size - 1; end > 0; end--)
	{
		/* Move current root to end */
		int temp = array[end];

		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);

		/* Call max heapify on the reduced heap */
		sift_down(array, 0, end - 1, size);
	}
}
