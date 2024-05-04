#include "deck.h"

void sort_deck(deck_node_t **deck);
deck_node_t *merge_sort(deck_node_t *head);
deck_node_t *merge(deck_node_t *first, deck_node_t *second);
deck_node_t *split(deck_node_t *head);
int compare_cards(const deck_node_t *card1, const deck_node_t *card2);

/**
 * sort_deck - Sorts a deck of cards using merge sort.
 * @deck: Double pointer to the head of the deck of cards.
 */
void sort_deck(deck_node_t **deck)
{
    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;

    *deck = merge_sort(*deck);
}

/**
 * merge_sort - Recursively sorts the deck using merge sort.
 * @head: The starting node of the deck.
 * Return: Pointer to the sorted deck.
 */
deck_node_t *merge_sort(deck_node_t *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    deck_node_t *second = split(head);

    head = merge_sort(head);
    second = merge_sort(second);

    return merge(head, second);
}

/**
 * split - Splits a deck into two halves.
 * @head: The start of the deck.
 * Return: Pointer to the second half of the deck.
 */
deck_node_t *split(deck_node_t *head)
{
    deck_node_t *fast = head, *slow = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    deck_node_t *temp = slow->next;
    slow->next = NULL;
    return temp;
}

/**
 * merge - Merges two halves of a deck into a sorted deck.
 * @first: First half of the deck.
 * @second: Second half of the deck.
 * Return: Pointer to the merged deck.
 */
deck_node_t *merge(deck_node_t *first, deck_node_t *second)
{
    if (!first)
        return second;
    if (!second)
        return first;

    if (compare_cards(first, second) <= 0)
    {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

/**
 * compare_cards - Compares two cards according to their suits and values.
 * @card1: First card node.
 * @card2: Second card node.
 * Return: <0 if card1 < card2, 0 if equal, >0 if card1 > card2
 */
int compare_cards(const deck_node_t *card1, const deck_node_t *card2)
{
   

