#include "sort.h"

/**
 * quick_sort - quickly sorts the array
 * Return: void
 * @array: array to be sorted
 * @size: the size of the aray
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_real(array, size, size, 0);
}

/**
 * quick_sort_real - real quicksort
 * Return: void
 * @array: array to be sorted
 * @size: size of the array
 * @original: original array to be printed
 * @ofst: how far the right the array is from the orignal array
 */

void quick_sort_real(int *array, size_t size, size_t original, size_t ofst)
{
	int pivot, swap, left = 0, right;

	if (size <= 1 || !array)
		return;
	right = left + 1;
	pivot = array[size - 1];
	while (left < (int) size - 1)
	{
		if (array[left] <= pivot)
		{
			left++;
			right++;
			continue;
		}
		if (right >= (int)size - 1)
			break;
		if (array[right] > pivot)
		{
			right++;
			continue;
		}
		swap = array[left];
		array[left] = array[right];
		array[right] = swap;
		left++;
		right = right + 1;
		print_array((array - ofst), original);
	}
	if (right == (int) size - 1 && array[left] > pivot)
	{
		swap = array[left];
		array[left] = array[size - 1];
		array[size - 1] = swap;
		print_array((array - ofst), original);
	}
	quick_sort_real(array, left, original, 0 + ofst);
	quick_sort_real(&array[left + 1], size - left - 1, original, 1 + left + ofst);
}
