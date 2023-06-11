#include "lists.h"

/**
* free_listint2 - frees a listint_t list.
* @head: entry into the linked list
*/

void free_listint2(listint_t **head)
{
	listint_t *temp, *temp1;

	if (*head == NULL)
	{
		return;
	}

	temp = temp1 = *head;
	*head = NULL;
	while (temp != NULL)
	{
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}
	free(temp);
}
