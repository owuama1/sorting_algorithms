#include "sort.h"
#include <stdio.h>

/**
 * swap_node - Swap a node with its previous one in a doubly linked list.
 * @node: Node to be swapped.
 * @list: Pointer to the head of the list.
 * Return: Pointer to the new position of the swapped node.
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;

	return (current);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_done = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = *list;
	while (swap_done == 1)
	{
		swap_done = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				swap_done = 1;
				print_list(*list);
			}
			else
			{
				node = node->next;
			}
		}

		if (swap_done == 0)
			break;

		swap_done = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swap_done = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
