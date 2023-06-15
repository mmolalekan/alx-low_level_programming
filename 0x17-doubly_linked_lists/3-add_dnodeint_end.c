#include "lists.h"

/**
* add_dnodeint_end - adds a new node at the end of a dlistint_t list.
* @head: entry point into the linked list
* @n: the data of the node
* Return: the address of the new element on success, NULL on failure
*/

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temp, *newNode;

	newNode = malloc(sizeof(dlistint_t));
	if (newNode == NULL)
	{
		return (NULL);
	}
	newNode->n = n;
	newNode->next = NULL;

	if (*head == NULL)
	{
		newNode->prev = NULL;
		*head = newNode;
		return (newNode);
	}

	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	newNode->prev = temp;
	temp->next = newNode;

	return (newNode);
}
