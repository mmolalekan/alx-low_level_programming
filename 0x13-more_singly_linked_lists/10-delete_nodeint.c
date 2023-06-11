#include "lists.h"

/**
* delete_nodeint_at_index - deletes the node
* at index index of a listint_t linked list.
* @head: entry into the linked list
* @ index: the index of the node that should be deleted
* Return: 1 on success, -1 on failure
*/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *del;
	unsigned int i;

	if (*head == NULL)
	{
		return (-1);
	}

	temp = *head;
	for (i = 0; i < index - 1; i++)
	{
		if (temp == NULL)
		{
			return (-1);
		}
		temp = temp->next;
	}

	del = temp->next;
	temp->next = del->next;
	free(del);

	return (1);
}
