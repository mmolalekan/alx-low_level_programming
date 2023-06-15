#include "lists.h"

/**
* insert_dnodeint_at_index -  inserts a new node at a given position.
* @h: entry point
* @idx: the index of the list where the new node should be added.
* @n: the data of the node
* Return: the address of the new node on success, or NULL on failure
*/

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp, *newNode;
	unsigned int i;

	if (*h == NULL)
		return (NULL);

	newNode = malloc(sizeof(dlistint_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = n;

	temp = *h;
	for (i = 1; i < idx; i++)
	{
		if (temp == NULL)
		{
			free(newNode);
			return (NULL);
		}
		temp = temp->next;
	}
	newNode->prev = temp;
	newNode->next = temp->next;
	temp->next = newNode;

	return (newNode);
}
