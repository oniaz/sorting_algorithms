#include "sort.h"

/**
 * nodeSwap - swaps two nodes, updates the pointer to the list head, and then
 * prints the list.
 * @node1: first node.
 * @node2: second node.
 * @listHead: double pointer to the list head.
 *
 * Return: nothing.
 */
void nodeSwap(listint_t **node1, listint_t **node2, listint_t **listHead)
{
	listint_t *tmp;

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

	if (!(*node1)->prev)
		*listHead = (*node1);
	print_list(*listHead);
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
	listint_t *n1, *n2, *n0;

	if (!list || !*list)
		return;

	n1 = *list;
	while (n1 && n1->next)
	{
		n2 = n1->next;

		if (n1->n > n2->n)
		{
			nodeSwap(&n1, &n2, list);

			while (n1 && n1->prev)
			{
				n0 = n1->prev;

				if (n0->n < n1->n || n1->n == n0->n)
					break;

				nodeSwap(&n0, &n1, list);
				n1 = n0;
			}
		}
		n1 = n2;
	}
}
