#include "lists.h"

/**
* pop_listint - deletes the head node of a listint_t linked list,
* and returns the head node’s data (n).
* @head: the entry point to the linked list
* Return: the head node’s data (n).
*/

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int data;

	if (*head == NULL)
	{
		return (0);
	}

	temp = *head;
	data = temp->n;

	if ((*head)->next == NULL)
	{
		*head = NULL;
	}
	else
	{
		*head = (*head)->next;
	}

	free(temp);
	return (data);
}
