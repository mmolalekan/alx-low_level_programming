#include "lists.h"

/**
* add_dnodeint - adds a new node at the beginning of a dlistint_t list.
* @head: the entry point into the doubly linked list
* @n: value of the node
* Return: the address of the new element on success, NULL on failure
*/

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newNode;

	newNode = malloc(sizeof(dlistint_t));
	if (newNode == NULL)
	{
		return (NULL);
	}

	newNode->prev = NULL;
	newNode->n = n;
	newNode->next = *head;
	*head = newNode;

	return (newNode);
}
