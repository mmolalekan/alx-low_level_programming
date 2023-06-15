#include "lists.h"

/**
* dlistint_len - returns the number of elements in a linked dlistint_t list.
* @h: the entry point into the doubly linked list
* Return: the number of nodes
*/

size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *temp;
	size_t count;

	temp = h;
	count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
