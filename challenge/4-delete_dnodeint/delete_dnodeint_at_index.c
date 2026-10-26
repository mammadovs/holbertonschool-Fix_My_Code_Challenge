#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index of a dlistint_t list.
 * @head: Double pointer to the head of the list.
 * @index: Index of the node to delete. Index starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved;
	dlistint_t *tmp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	saved = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(saved);
		return (1);
	}

	for (i = 0; *head != NULL && i < index; i++)
	{
		*head = (*head)->next;
	}

	if (*head == NULL)
	{
		*head = saved;
		return (-1);
	}

	(*head)->prev->next = (*head)->next;

	if ((*head)->next != NULL)
		(*head)->next->prev = (*head)->prev;

	tmp = *head;
	*head = saved;
	free(tmp);

	return (1);
}
