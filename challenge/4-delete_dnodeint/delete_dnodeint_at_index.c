#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at a given index of a dlistint_t list
 * @head: Double pointer to the head of the list
 * @index: Index of the node that should be deleted. Index starts at 0
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;

    /* If we need to delete the head node */
    if (index == 0)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    /* Traverse to the node at the given index */
    for (i = 0; current != NULL && i < index; i++)
    {
        current = current->next;
    }

    /* If index is out of range */
    if (current == NULL)
        return (-1);

    /* Unlink the node */
    if (current->next != NULL)
        current->next->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = current->next;

    free(current);
    return (1);
}

