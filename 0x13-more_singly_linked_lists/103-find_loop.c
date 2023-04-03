#include <stdlib.h>
#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: head of a list.
 *
 * Return: the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *p2;
    listint_t *prev;
    listint_t *tmp;

    if (!head)
        return (NULL);

    p2 = head;
    prev = head;
    while (head && p2 && p2->next)
    {
        head = head->next;
        p2 = p2->next->next;

        if (head == p2)
        {
            head = prev;
            prev =  p2;
            while (1)
            {
                p2 = prev;
                while (p2->next != head && p2->next != prev)
                {
                    p2 = p2->next;
                }
                if (p2->next == head)
                    break;

                head = head->next;
            }
            tmp = p2->next;
            p2->next = NULL;
            return (tmp);
        }
    }

    return (NULL);
}
