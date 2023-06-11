#include "lists.h"
#include <stdio.h>
/**
* insert_nodeint_at_index - inserts a new node at a given position.
* @head: entry point to the linked list
* @idx: the index of the list where the new node should be added.
* @n: the value to be assigned to the node
* Return: address of the node on success, NULL on failure
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *temp, *newNode;
	unsigned int i;

	if (*head == NULL && idx != 0)
	{
		return (NULL);
	}

	temp = *head;
	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
	{
		return (NULL);
	}
	newNode->n = n;

	for (i = 0; i < idx - 1; i++)
	{
		if (temp == NULL)
		{
			free(newNode);
			return (NULL);
		}
		temp = temp->next;
	}

	newNode->next = temp->next;
	temp->next = newNode;
	return (newNode);
}
