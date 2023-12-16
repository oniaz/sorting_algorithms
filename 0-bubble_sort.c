#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using the bubble sort algorithm.
 * The array gets printed after each swap.
 * @array: pointer to the array to be sorted.
 * @size: size of the array
 *
 * Return: nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, swaps;
	int tmp;

	if (!array || size < 2)
		return;

	do {
		swaps = 0;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				swaps++;
			}
		}
	} while (swaps > 0);
}
