#include "lists.h"

/**
* print_list - prints all the elements of a list_t list.
* @h: head of the list
* Return: the number of nodes
*/

size_t print_list(const list_t *h)
{
	const list_t *temp;
	size_t count;

	count = 0;
	temp = h;
	while (temp != NULL)
	{
		if (temp->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%d] %s\n", temp->len, temp->str);
		}
		temp = temp->next;
		count += 1;
	}
	return (count);
}
