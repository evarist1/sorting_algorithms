#include "sort.h"

void swap_ints(int *x, int *z);
void max_heapify(int *array, size_t size, size_t floor, size_t grass);
void heap_sort(int *array, size_t size);

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
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @floor: The index of the base row of the tree.
 * @grass: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t floor, size_t grass)
{
	size_t back, front, large;

	back = 2 * grass + 1;
	front = 2 * grass + 2;
	large = grass;

	if (back < floor && array[back] > array[large])
		large = back;
	if (front < floor && array[front] > array[large])
		large = front;

	if (large != grass)
	{
		swap_ints(array + grass, array + large);
		print_array(array, size);
		max_heapify(array, size, floor, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 * order using the heap sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int b;

	if (array == NULL || size < 2)
		return;

	for (b = (size / 2) - 1; b >= 0; b--)
		max_heapify(array, size, size, b);

	for (b = size - 1; b > 0; b--)
	{
		swap_ints(array, array + b);
		print_array(array, size);
		max_heapify(array, size, b, 0);
	}
}
