#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array.
 * @array: The array.
 * @i: Index of the first element.
 * @j: Index of the second element.
 */
void swap(int *array, ssize_t i, ssize_t j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/**
 * lomuto_partition - Lomuto partition sorting scheme implementation.
 * @array: The array.
 * @first: Index of the first array element.
 * @last: Index of the last array element.
 * @size: Size of the array.
 *
 * Return: The position of the last element sorted.
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}

/**
 * qs - Quicksort algorithm implementation.
 * @array: The array.
 * @first: Index of the first array element.
 * @last: Index of the last array element.
 * @size: Size of the array.
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}

/**
 * quick_sort - Prepares the terrain for the quicksort algorithm.
 * @array: The array.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}

