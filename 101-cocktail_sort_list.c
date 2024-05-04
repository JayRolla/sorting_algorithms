#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list using the cocktail shaker sort
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *current, *tail = NULL;

    if (!list || !*list || !(*list)->next)
        return;

    while (swapped)
    {
        swapped = 0;
        current = *list;
        while (current->next && current != tail)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
            }
            else
            {
                current = current->next;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        tail = current;
        while (current->prev && current != *list)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                print_list(*list);
                swapped = 1;
            }
            else
            {
                current = current->prev;
            }
        }
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node_a: Pointer to the first node
 * @node_b: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
{
    listint_t *prev_a, *next_b;

    if (!node_a || !node_b)
        return;

    prev_a = node_a->prev;
    next_b = node_b->next;

    if (prev_a)
        prev_a->next = node_b;
    if (next_b)
        next_b->prev = node_a;

    node_a->next = next_b;
    node_b->prev = prev_a;
    node_a->prev = node_b;
    node_b->next = node_a;

    if (prev_a == NULL)
        *list = node_b;
}
