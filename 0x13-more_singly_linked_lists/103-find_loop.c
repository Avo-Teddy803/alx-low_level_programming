#include "lists.h"

/**
 *
 * find_loop_start - finds the start of a loop in a linked list.
 * @list_head: the head of the linked list.
 *
 *
 * Returns the address of the node where the loop starts, or NULL if there is no loop.
 */

listint_t *find_loop_start(listint_t *list_head)
{
    listint_t *slow, *fast, *node1, *node2;

    slow = fast = list_head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            node1 = slow;
            node2 = list_head;

            while (node1 && node2)
            {
                if (node1 == node2)
                {
                    return node1;
                }

                node1 = node1->next;
                node2 = node2->next;
            }
        }
    }

    return NULL;
}

