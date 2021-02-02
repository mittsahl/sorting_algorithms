#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using shell sort
 * @array: the array
 * @size: the array size
 *
 * Return: Always 0
 */
void shell_sort(int *array, size_t size)
{
	size_t space = 0, idx, num;
	int mid = 0;


	if (array == NULL || size < 2)
		return;
	while (space < size)
	{
		space = space * 3 + 1;
	}
	space = (space - 1) / 3;
	while (space > 0)
	{
		for (idx = space; idx < size; idx++)
		{
			mid = array[idx];
			for (num = idx; array[num - space] > mid; num = num - space)
			{
				array[num] = array[num - space];
			}
			array[num] = mid;
		}
		print_array(array, size);
		space = (space - 1) / 3;
	}
}
