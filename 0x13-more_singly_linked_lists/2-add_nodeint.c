#include "lists.h"

/**
* add_nodeint - adds a new node at the beginning of a listint_t list.
* @head: head of the linked list
* @n: a member of the struct
* Return: the address of the new element on success, NULL on failure
*/

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newNode;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
	{
		return (NULL);
	}

	newNode->n = n;
	newNode->next = *head;
	*head = newNode;
	return (newNode);
}
