#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swap two nodes in a doubly linked list.
 * @list: Pointer to the head of the list.
 * @a: First node to swap.
 * @b: Second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	b->next = a;
	a->prev = b;

	if (!b->prev)
		*list = b;
}

/**
 * insertion_sort_list - Sort a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *insert;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		next = current->next;
		insert = current->prev;

		while (insert && current->n < insert->n)
		{
			swap_nodes(list, insert, current);
			print_list(*list);
			insert = current->prev;
		}
		current = next;
	}
}
