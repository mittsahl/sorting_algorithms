#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using bubble sort
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int swapped = 0, idx, tmp;

	while(swapped == 0)
	{
		swapped = 1;
		for (idx = 0; idx < size; idx++)
		{
			if (array[idx] > array[idx + 1])
			{
				tmp = array[idx];
				array[idx] = array[idx + 1];
				array[idx + 1] = tmp;
				swapped = 0;
				print_array(array, size);
			}
		}
	}
}