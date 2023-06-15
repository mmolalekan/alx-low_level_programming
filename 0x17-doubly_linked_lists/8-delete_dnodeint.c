#include "lists.h"

/**
* delete_dnodeint_at_index - deletes the node at the specified list index.
* @head: entry point
* @index: the index of the node that should be deleted.
* Return: 1 on success, -1 on failure
*/

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp, *this, *that;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	temp = *head;
	for (i = 0; i < index; i++)
	{
		if (temp == NULL)
		{
			return (-1);
		}
		temp = temp->next;
	}
	this = temp->prev;
	that = temp->next;
	this->next = that;
	if (that != NULL)
		that->prev = this;
	free(temp);

	return (1);
}
