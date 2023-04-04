#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @head: double pointer to head of a list
 *
 * This function frees a listint_t list and sets the head to NULL.
 */
void free_listint2(listint_t **head)
{
	listint_t *current, *next;

	if (head == NULL)
		return;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
