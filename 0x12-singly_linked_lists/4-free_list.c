#include "lists.h"

/**
* free_list - frees a list_t list.
* @head: entry into a linked list
*/

void free_list(list_t *head)
{
	list_t *temp, *nextNode;

	if (head == NULL)
	{
		return;
	}
	else
	{
		nextNode = head;
		while (nextNode != NULL)
		{
			temp = nextNode;
			nextNode = nextNode->next;
			free(temp->str);
			free(temp);
		}
	}
}
