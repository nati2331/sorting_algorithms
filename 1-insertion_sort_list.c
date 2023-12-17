#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the linked list.
 */

void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current)
    {
        listint_t *insert_pos = current->prev;
        listint_t *temp = current->next;

        while (insert_pos != NULL && insert_pos->n > current->n)
        {
            insert_pos = insert_pos->prev;
        }

        if (insert_pos != current->prev)
        {
            if (current->next != NULL)
                current->next->prev = current->prev;

            if (current->prev != NULL)
                current->prev->next = current->next;

            current->next = (insert_pos != NULL) ? insert_pos->next : *list;
            current->prev = insert_pos;

            if (insert_pos != NULL)
                insert_pos->next = current;
            else
                *list = current;
        }

        current = temp;
        print_list(*list);
    }
}
