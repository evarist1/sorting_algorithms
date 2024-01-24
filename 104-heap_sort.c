#include "sort.h"

/**
 * heapify - Build a max heap from the array
 * @array: The array to be transformed into a heap
 * @size: Size of the array
 * @x: Index to start heapifying from
 */
void heapify(int *array, size_t size, size_t x)
{
	size_t largest = x;
	size_t left = 2 * x + 1;
	size_t right = 2 * x + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != x)
	{
		int temp = array[x];
		array[x] = array[largest];
		array[largest] = temp;

		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending
 * order using heap sort
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */

void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (int i = size - 1; i > 0; i--)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		heapify(array, i, 0);
	}
}
