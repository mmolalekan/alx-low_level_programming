#include "lists.h"
#include <string.h>

/**
* add_node_end - adds a new node at the end of a list_t list.
* @head: head of the list
* @str: the string to be inserted into the linked list
* Return: the new node
*/

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newNode, *temp;

	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
	{
		return (NULL);
	}

	newNode->len = strlen(str);
	newNode->str = strdup(str);
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}

	return (newNode);
}
