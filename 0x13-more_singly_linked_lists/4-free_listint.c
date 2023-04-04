#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - frees a linked list
 * @head: head of a list.
 *
 * Return: no return.
 */
void free_listint2(listint_t **head)
{
    listint_t *temp;

    if (head == NULL || *head == NULL)
        return;

    while (*head != NULL)
    {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
}
