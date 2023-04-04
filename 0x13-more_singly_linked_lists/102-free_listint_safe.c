#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: double pointer to head of list
 *
 * Return: size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
    size_t nnodes = 0;
    listp_t *head = NULL, *tmp, *prev;
    listint_t *current;

    if (h == NULL || *h == NULL)
        return (0);

    while (*h != NULL)
    {
        tmp = malloc(sizeof(listp_t));
        if (tmp == NULL)
        {
            free_listp(&head);
            exit(98);
        }
        tmp->p = (void *)*h;
        tmp->next = head;
        head = tmp;
        prev = NULL;
        current = *h;
        while (current != NULL)
        {
            if (current == tmp->p)
            {
                *h = NULL;
                free_listp(&head);
                return (nnodes);
            }
            prev = current;
            current = current->next;
        }
        nnodes++;
        *h = (*h)->next;
        free(prev);
    }
    *h = NULL;
    free_listp(&head);
    return (nnodes);
}

/**
 * free_listp - frees a linked list
 * @head: pointer to head of list
 *
 * Return: no return
 */
void free_listp(listp_t **head)
{
    listp_t *current;

    while (*head != NULL)
    {
        current = *head;
        *head = (*head)->next;
        free(current);
    }
}
