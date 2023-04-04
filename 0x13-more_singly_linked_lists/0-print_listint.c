#include "lists.h"

/**
 * print_listint_safe - prints all the elements of a list.
 * @head: head of a list.
 *
 * Return: numbers of nodes.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node_count = 0;
	const listint_t *current = head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		node_count++;
	}

	return (node_count);
}
