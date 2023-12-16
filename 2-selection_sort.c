#include "sort.h"

/**
 * selection_sort - sorts an array of integers using the selection sort
 * algorithm. The array gets printed after each swap.
 * @array: pointer to the array to be sorted.
 * @size: size of the array
 *
 * Return: nothing.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		int minValue = array[i];
		size_t minIndex = i;

		for (j = i; j < size; j++)
		{
			if (array[j] < minValue)
			{
				minValue = array[j];
				minIndex = j;
			}
		}
		if (minValue != array[i])
		{
			array[minIndex] = array[i];
			array[i] = minValue;
			print_array(array, size);
		}
	}
}
