#include "sort.h"

void merge_subarr(int *sarr, int *buf, size_t f, size_t mid,
size_t b);
void merge_sort_recursive(int *sarr, int *buf, size_t f, size_t b);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers.
 * @sarr: A subarray of an array of integers to sort.
 * @buf: A buffer to store the sorted subarray.
 * @f: The front index of the array.
 * @mid: The middle index of the array.
 * @b: The back index of the array.
 */
void merge_subarr(int *sarr, int *buf, size_t f, size_t mid,
		size_t b)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sarr + f, mid - f);

	printf("[right]: ");
	print_array(sarr + mid, b - mid);

	for (i = f, j = mid; i < mid && j < b; k++)
		buf[k] = (sarr[i] < sarr[j]) ? sarr[i++] : sarr[j++];
	for (; i < mid; i++)
		buf[k++] = sarr[i];
	for (; j < b; j++)
		buf[k++] = sarr[j];
	for (i = f, k = 0; i < b; i++)
		sarr[i] = buf[k++];

	printf("[Done]: ");
	print_array(sarr + f, b - f);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @sarr: A subarray of an array of integers to sort.
 * @buf: A buffer to store the sorted result.
 * @f: The front index of the subarray.
 * @b: The back index of the subarray.
 */
void merge_sort_recursive(int *sarr, int *buf, size_t f, size_t b)
{
	size_t mid;

	if (b - f > 1)
	{
		mid = f + (b - f) / 2;
		merge_sort_recursive(sarr, buf, f, mid);
		merge_sort_recursive(sarr, buf, mid, b);
		merge_subarr(sarr, buf, f, mid, b);
	}
}

/**
 * merge_sort - Sort array of integers in ascending
 * order using the merge sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	merge_sort_recursive(array, buf, 0, size);

	free(buf);
}
