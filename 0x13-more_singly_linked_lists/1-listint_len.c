#include "lists.h"
#include <stdio.h>
/**
* listint_len - returns the number of elements in a linked listint_t list.
* @h: the head of the linked list
* Return: the number of elements
*/

size_t listint_len(const listint_t *h)
{
	const listint_t *temp;
	size_t count;

	temp = h;
	count  = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
