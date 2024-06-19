#ifndef DECK_H
#define DECK_H

#include <stddef.h>

/**
 * enum kind_e - Suit of a playing card
 *
 * @SPADE: Spade suit
 * @HEART: Heart suit
 * @CLUB: Club suit
 * @DIAMOND: Diamond suit
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Structure defining a playing card
 *
 * @value: Value of the card (e.g., "Ace", "2", ..., "King")
 * @kind: Kind of the card (SPADE, HEART, CLUB, DIAMOND)
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Structure defining a node in a deck of cards
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node in the deck
 * @next: Pointer to the next node in the deck
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* Function prototype for sorting a deck of cards */
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
