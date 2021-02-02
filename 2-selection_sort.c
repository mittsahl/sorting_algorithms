#include "sort.h"

/**
 * swap - swaps two integers in an array
 * Return: void
 * @a: frst integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * selection_sort - picks first element and swaps with the smallest element
 * Return: void
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	int i, j, lowest;

	for (i = 0; i < (int)size - 1; i++)
	{
		lowest = i;
		for (j = i + 1; j < (int)size; j++)
		{
			if (array[j] < array[lowest])
				lowest = j;
		}
		swap(&array[lowest], &array[i]);
	}
}
