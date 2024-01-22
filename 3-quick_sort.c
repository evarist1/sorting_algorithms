#include "sort.h"

void swap_ints(int *y, int *z);
int lomuto_partition(int *array, size_t size, int begin, int end);
void lomuto_sort(int *array, size_t size, int begin, int end);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Order a subset of an array of integers according to
 * the lomuto partition scheme
 *
 * @array: The array of integers.
 * @size: The size of the array.
 * @begin: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int begin, int end)
{
	int *pivot, up, down;

	pivot = array + end;
	for (up = down = begin; down < end; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		swap_ints(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - Implements the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @begin: The starting index of the array partition to order.
 * @end: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int begin, int end)
{
	int p;

	if (end - begin > 0)
	{
		p = lomuto_partition(array, size, begin, end);
		lomuto_sort(array, size, begin, p - 1);
		lomuto_sort(array, size, p + 1, end);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
