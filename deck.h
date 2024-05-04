#ifndef DECK_H
#define DECK_H

#include <stdlib.h> /* Required for size_t and NULL */

/**
 * enum kind_e - Enumeration of card suits
 * @SPADE: 0, represents the suit of spades
 * @HEART: 1, represents the suit of hearts
 * @CLUB: 2, represents the suit of clubs
 * @DIAMOND: 3, represents the suit of diamonds
 */
typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * struct card_s - Represents a playing card
 * @value: Value of the card, from "Ace" to "King"
 * @kind: Kind of the card, from enum kind_e
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Node in a doubly linked list of cards
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node in the list
 * @next: Pointer to the next node in the list
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

#endif /* DECK_H */
