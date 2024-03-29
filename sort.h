#ifndef SA
#define SA

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* sorting fucntions */
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);

/* utility functions */
void nodeSwap(listint_t **node1, listint_t **node2, listint_t **listHead);
void Lomuto(int *array, size_t size, ssize_t startIndex, ssize_t endIndex);

/* printing fucntions */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void quick_sort(int *array, size_t size);

#endif
