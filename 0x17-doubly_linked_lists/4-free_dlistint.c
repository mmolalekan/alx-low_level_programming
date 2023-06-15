#include "lists.h"

/**
* free_dlistint - frees a dlistint_t list.
* @head: the entry point into the linked list
*/

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp, *freed;

	temp = head;
	while (temp != NULL)
	{
		freed = temp;
		temp = temp->next;
		free(freed);
	}
}
