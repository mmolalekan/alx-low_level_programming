#include "lists.h"

/**
* get_nodeint_at_index - returns the nth node of a listint_t linked list.
* @head: entry into the linked list
* @index: the index of the node, starting at 0
* Return: the nth node on success, NULL on failure
*/

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *temp;
	unsigned int i;

	if (head == NULL)
	{
		return (NULL);
	}

	temp = head;
	for (i = 0; i < index; i++)
	{
		if (temp->next == NULL)
		{
			return (NULL);
		}
		temp = temp->next;
	}
	return (temp);
}
