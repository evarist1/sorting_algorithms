#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int peak, j;

	for (peak = array[0], j = 1; j < size; j++)
	{
		if (array[j] > peak)
			peak = array[j];
	}

	return (peak);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *tally, *sorted, peak, j;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	peak = get_max(array, size);
	tally = malloc(sizeof(int) * (peak + 1));
	if (tally == NULL)
	{
		free(sorted);
		return;
	}

	for (j = 0; j < (peak + 1); j++)
		tally[j] = 0;
	for (j = 0; j < (int)size; j++)
		tally[array[j]] += 1;
	for (j = 0; j < (peak + 1); j++)
		tally[j] += tally[j - 1];
	print_array(tally, peak + 1);

	for (j = 0; j < (int)size; j++)
	{
		sorted[tally[array[j]] - 1] = array[j];
		tally[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = sorted[j];

	free(sorted);
	free(tally);
}
