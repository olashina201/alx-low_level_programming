#include <string.h>
#include "lists.h"
#include <stdlib.h>

/**
 * add_node_end - function that add a node to head of linked list
 * @head: head
 * @str: str
 * Return: pointer to new head of list
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *temp, *new_node;
	unsigned int length = 0;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	while (str[length])
		length++;

	new_node->len = length;
	new_node->str = strdup(str);
	if (*head == NULL)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		new_node->next = NULL;
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	return (new_node);
}
