#include <string.h>
#include "lists.h"
#include <stdlib.h>

/**
 * add_node - function that add a node to head of linked list
 * @head: head
 * @str: str
 * Return: pointer to new head of list
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *temp;
	int length = 0;

	temp = malloc(sizeof(list_t));
	if (temp == NULL)
		return (NULL);

	while (str[length])
		length++;

	temp->len = length;
	temp->str = strdup(str);
	temp->next = *head;
	*head = temp;
	return (temp);
}
