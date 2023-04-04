#include "lists.h"

/**
 * count_nodes - counts the number of nodes in a linked list
 * @h: pointer to the head of the list
 * @count: pointer to a counter for the nodes
 *
 * Return: the number of nodes in the list
 */
void count_nodes(const listint_t *h, size_t *count)
{
	if (h == NULL)
		return;

	*count += 1;
	count_nodes(h->next, count);
}

/**
 * listint_len - returns the number of elements in
 * a linked list.
 * @h: head of a list.
 *
 * Return: the number of nodes in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	count_nodes(h, &count);

	return (count);
}
