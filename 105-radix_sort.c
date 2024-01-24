#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int imp, int *buf);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int big, b;

	for (big = array[0], b = 1; b < size; b++)
	{
		if (array[b] > big)
			big = array[b];
	}

	return (big);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 * in ascending order using the counting sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 * @imp: The significant digit to sort on.
 * @buf: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int imp, int *buf)
{
	int list[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t b;

	for (b = 0; b < size; b++)
		list[(array[b] / imp) % 10] += 1;

	for (b = 0; b < 10; b++)
		list[b] += list[b - 1];

	for (b = size - 1; (int)b >= 0; b--)
	{
		buf[list[(array[b] / imp) % 10] - 1] = array[b];
		list[(array[b] / imp) % 10] -= 1;
	}

	for (b = 0; b < size; b++)
		array[b] = buf[b];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * order using the radix sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int big, imp, *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	big = get_max(array, size);
	for (imp = 1; big / imp > 0; imp *= 10)
	{
		radix_counting_sort(array, size, imp, buf);
		print_array(array, size);
	}

	free(buf);
}
