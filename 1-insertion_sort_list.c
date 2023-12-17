#include "sort.h"

void nodeSwap(listint_t **node1, listint_t **node2)
{
    listint_t *tmp;
printf("before\n");
printf("node1:\n prev:%d - node1:%d - next:%d\n", (*node1)->prev->n, (*node1)->n, (*node1)->next->n);
printf("node2:\n prev:%d - node2:%d - next:%d\n", (*node2)->prev->n, (*node2)->n, (*node2)->next->n);

    if ((*node1)->prev)
        (*node1)->prev->next = (*node2);
    if ((*node2)->next)
        (*node2)->next->prev = (*node1);

    (*node1)->next = (*node2)->next;
    (*node2)->prev = (*node1)->prev;
    (*node1)->prev = (*node2);
    (*node2)->next = (*node1);

    (tmp) = (*node1);
    (*node1) = (*node2);
    (*node2) = tmp;

printf("after\n");
printf("node1:\n prev:%d - node1:%d - next:%d\n", (*node1)->prev->n, (*node1)->n, (*node1)->next->n);
printf("node2:\n prev:%d - node2:%d - next:%d\n", (*node2)->prev->n, (*node2)->n, (*node2)->next->n);
    // printf("inside: ");
    // print_list(*node1);
    // printf("\n");
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers using the
 * insertion sort algorithm. The array gets printed after each swap.
 * @list: double pointer to the head of the list.
 *
 * Return: nothing.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *left = *list, *right, *farLeft;

    if (!list || !*list)
        return;

    while (left && left->next)
    {
        if (left->n > left->next->n)
        {
            right = left->next;
            // swap nodes
            nodeSwap(&left, &right);
            if (!left->prev)
                *list = left;
            print_list(*list);
            

            while (left && left->prev)
            {
                farLeft = left->prev;
                if (left->n > farLeft->n)
                    break;

                if (farLeft->n > left->n)
                {
                    nodeSwap(&left, &farLeft);
                    if (!left->prev)
                        *list = left;
                    print_list(*list);
                    break;
                }
                left = left->prev;
            }
        }
        // onto the next node
        else
            left = left->next;
    }
}