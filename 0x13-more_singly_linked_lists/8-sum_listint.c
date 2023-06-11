#include "lists.h"

/**
* sum_listint - returns the sum of all the data (n) of a listint_t linked list.
* @head: entry point of the linked list
* Return: the sum on success, 0 if the list is empty
*/

int sum_listint(listint_t *head)
{
	listint_t *temp;
	int sum;

	if (head == NULL)
	{
		return (0);
	}

	sum = 0;
	temp = head;
	while (temp != NULL)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}
