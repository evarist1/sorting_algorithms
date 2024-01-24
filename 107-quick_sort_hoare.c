#include "sort.h"

void swap_ints(int *y, int *z);
int hoare_partition(int *array, size_t size, int back, int front);
void hoare_sort(int *array, size_t size, int back, int front);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - Order a subset of an array of integers
 * according to the hoare partition scheme.
 *
 * @array: The array of integers.
 * @size: The size of the array.
 * @back: The starting index of the subset to order.
 * @front: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int back, int front)
{
	int joint, v, w;

	joint = array[front];
	for (v = back - 1, w = front + 1; v < w;)
	{
		do {
			v++;
		} while (array[v] < joint);
		do {
			w--;
		} while (array[w] > joint);

		if (v < w)
		{
			swap_ints(array + v, array + w);
			print_array(array, size);
		}
	}

	return (v);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @back: The starting index of the array partition to order.
 * @front: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int back, int front)
{
	int p;

	if (front - back > 0)
	{
		p = hoare_partition(array, size, back, front);
		hoare_sort(array, size, back, p - 1);
		hoare_sort(array, size, p, front);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
