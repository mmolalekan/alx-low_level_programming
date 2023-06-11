#include "lists.h"

/**
* free_listint -  frees a listint_t list.
* @head: the entry point to the linked list
*/

void free_listint(listint_t *head)
{
	listint_t *temp;

	if (head == NULL)
	{
		return;
	}

	temp = head;
	while (temp != NULL)
	{
		head = temp;
		temp = temp->next;
		free(head);
	}
	free(temp);
}
