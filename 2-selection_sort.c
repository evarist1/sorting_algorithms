#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @y: The first integer to swap.
 * @z: The second integer to swap.
 */
void swap_ints(int *y, int *z)
{
	int tmp;

	tmp = *y;
	*y = *z;
	*z = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * using the selection sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *m;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		m = array + i;
		for (j = i + 1; j < size; j++)
			m = (array[j] < *m) ? (array + j) : m;

		if ((array + i) != m)
		{
			swap_ints(array + i, m);
			print_array(array, size);
		}
	}
}
