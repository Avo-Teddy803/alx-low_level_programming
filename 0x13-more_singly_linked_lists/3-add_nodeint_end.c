#include "lists.h"

/**
 * add_node_at_end - adds a new node at the end of a listint_t list
 * @head: pointer to the head of the list
 * @data: data to be added to the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_node_at_end(listint_t **head, const int data)
{
	listint_t *new_node, *current;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = data;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}

	return (new_node);
}
