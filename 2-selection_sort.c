#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the Selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
    size_t i, index;
    size_t tmp, swap;

    if (array == NULL)
        return;

    for (i = 0; i < size; i++)
    {
        tmp = i;

        for (index = i + 1; index < size; index++)
        {
            if (array[tmp] > array[index])
            {
                tmp = index;
            }
        }

        swap = array[i];
        array[i] = array[tmp];
        array[tmp] = swap;

        if (i != tmp)
            print_array(array, size);
    }
}
