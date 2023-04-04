#include "lists.h"

/**
 * free_listint2 - frees a linked list and sets the head to NULL
 * @head: pointer to head of a list.
 *
 * Return: no return.
 */
void free_listint2(listint_t **head)
{
    listint_t *temp;

    if (!head)
        return;

    while (*head)
    {
        temp = (*head);
        (*head) = (*head)->next;
        free(temp);
    }
}
