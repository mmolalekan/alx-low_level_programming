#include "lists.h"
#include <string.h>

/**
* add_node - adds a new node at the beginning of a list_t list.
* @head: the head of the list
* @str: string to be added to the created node
* Return: new node
*/

list_t *add_node(list_t **head, const char *str)
{
	list_t *newNode;

	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
	{
		return (NULL);
	}
	newNode->next = *head;
	newNode->len = strlen(str);
	newNode->str = strdup(str);
	*head = newNode;
	return (newNode);
}
