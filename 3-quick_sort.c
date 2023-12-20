#include "sort.h"

/**
 * Lomuto - sorts a given partition of an array of integers using the quick
 * sort algorithm with the Lomuto partition scheme. The array gets printed
 * after each swap.
 * @array: pointer to the array to be sorted.
 * @size: size of the array.
 * @startIndex: first index of the array partition.
 * @endIndex: last index of the array partition.
 *
 * Return: nothing.
 */
void Lomuto(int *array, size_t size, int startIndex, int endIndex)
{
	int swapIndex = startIndex, pivot = endIndex, tmp;
	size_t i;

	if (startIndex == endIndex || startIndex > endIndex)
		return;

	for (i = startIndex; i < endIndex + 1; i++)
	{
		if (array[i] < array[pivot] || array[i] == array[pivot])
		{
			/* swap */
			if (array[swapIndex] != array[i])
			{
				tmp = array[swapIndex];
				array[swapIndex] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
			if (i != pivot)
				swapIndex++;
		}
	}

	Lomuto(array, size, startIndex, swapIndex - 1);
	Lomuto(array, size, swapIndex + 1, endIndex);
}

/**
 * quick_sort - sorts an array of integers using the quick sort algorithm with
 * the Lomuto partition scheme. The array gets printed after each swap.
 * @array: pointer to the array to be sorted.
 * @size: size of the array.
 *
 * Return: nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	Lomuto(array, size, 0, size - 1);
}
