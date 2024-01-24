/*
 * File: 106-bitonic_sort.c
 * Auth: Brennan D Baraban
 */

#include "sort.h"

void swap_ints(int *y, int *z);
void bitonic_merge(int *array, size_t size, size_t begin, size_t sq,
		char run);
void bitonic_seq(int *array, size_t size, size_t begin, size_t sq, char run);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @begin: The starting index of the sequence in array to sort.
 * @sq: The size of the sequence to sort.
 * @run: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t begin, size_t sq,
		char run)
{
	size_t k, hop = sq / 2;

	if (sq > 1)
	{
		for (k = begin; k < begin + hop; k++)
		{
			if ((run == UP && array[k] > array[k + hop]) ||
			    (run == DOWN && array[k] < array[k + hop]))
				swap_ints(array + k, array + k + hop);
		}
		bitonic_merge(array, size, begin, hop, run);
		bitonic_merge(array, size, begin + hop, hop, run);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @begin: The starting index of a block of the building bitonic sequence.
 * @sq: The size of a block of the building bitonic sequence.
 * @run: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t begin, size_t sq, char run)
{
	size_t t = sq / 2;
	char *str = (run == UP) ? "UP" : "DOWN";

	if (sq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sq, size, str);
		print_array(array + begin, sq);

		bitonic_seq(array, size, begin, t, UP);
		bitonic_seq(array, size, begin + t, t, DOWN);
		bitonic_merge(array, size, begin, sq, run);

		printf("Result [%lu/%lu] (%s):\n", sq, size, str);
		print_array(array + begin, sq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
