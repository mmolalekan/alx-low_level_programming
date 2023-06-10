#include "lists.h"

/**
* list_len - returns the number of elements in a linked list_t list.
* @h: the head of the list
* Return: the number of elements in the linked list
*/

size_t list_len(const list_t *h)
{
	const list_t *temp;
	size_t count;

	count = 0;
	temp = h;
	while (temp != NULL)
	{
		temp = temp->next;
		count += 1;
	}
	return (count);
}
