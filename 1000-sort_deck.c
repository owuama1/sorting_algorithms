#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * compare_cards - Compare function for qsort to compare two deck_node_t nodes
 * @a: Pointer to the first deck_node_t pointer
 * @b: Pointer to the second deck_node_t pointer
 *
 * Return: Negative value if a should come before b, positive value if b should
 *		   come before a, and zero if they are equal
 */
int compare_cards(const void *a, const void *b)
{
	const deck_node_t *node_a = *(const deck_node_t **)a;
	const deck_node_t *node_b = *(const deck_node_t **)b;

	int value_a = 0;
	int value_b = 0;
	int i;

	static const char *const values[] = {
		"Ace",	  /* Index 0 */
		"2",	  /* Index 1 */
		"3",	  /* Index 2 */
		"4",	  /* Index 3 */
		"5",	  /* Index 4 */
		"6",	  /* Index 5 */
		"7",	  /* Index 6 */
		"8",	  /* Index 7 */
		"9",	  /* Index 8 */
		"10",	  /* Index 9 */
		"Jack",   /* Index 10 */
		"Queen",  /* Index 11 */
		"King"	  /* Index 12 */
	};


	/* Compare by kind first */
	if (node_a->card->kind != node_b->card->kind)
		return (node_a->card->kind - node_b->card->kind);


	for (i = 0; i < 13; ++i)
	{
		if (strcmp(node_a->card->value, values[i]) == 0)
		{
			value_a = i;
		}
		if (strcmp(node_b->card->value, values[i]) == 0)
			value_b = i;
	}
	return (value_a - value_b);
}

/**
 * sort_deck - Sorts a deck of cards in ascending order by kind and value
 * @deck: Double pointer to the head of the deck of cards
 */
void sort_deck(deck_node_t **deck)
{
	size_t count = 0, i;
	deck_node_t *current;
	deck_node_t **array;

	/* Count number of nodes */
	current = *deck;
	while (current)
	{
		count++;
		current = current->next;
	}

	/* Allocate array of pointers */
	array = malloc(count * sizeof(*array));
	if (array == NULL)
		return;

	/* Populate array with pointers to nodes */
	i = 0;
	current = *deck;
	while (current)
	{
		array[i++] = current;
		current = current->next;
	}

	/* Sort array of pointers */
	qsort(array, count, sizeof(*array), compare_cards);

	/* Relink nodes based on sorted array */
	for (i = 0; i < count - 1; i++)
	{
		array[i]->next = array[i + 1];
		array[i + 1]->prev = array[i];
	}
	array[count - 1]->next = NULL;
	*deck = array[0];

	free(array); /* Free temporary array */
}
