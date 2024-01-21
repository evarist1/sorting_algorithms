#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Print elements of an array.
 * @array: The array to print.
 * @size: The size of the array.
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
	printf("%d", array[i]);
	
	if (i < size - 1)
	printf(", ");
	}
	printf("\n");
}
