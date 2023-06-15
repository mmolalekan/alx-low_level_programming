#include "lists.h"

/**
* sum_dlistint - returns the sum of all the data of a the linked list.
* @head: entry point
* Return: the sum of all the data.
*/

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *temp;
	int count;

	if (head == NULL)
		return (0);

	count  = 0;
	temp = head;
	while (temp != NULL)
	{
		count += temp->n;
		temp = temp->next;
	}
	return (count);
}
