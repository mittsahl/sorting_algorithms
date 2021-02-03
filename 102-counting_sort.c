#include "sort.h"

void counting_sort(int *array, size_t size)
{
	int *count, *final, highest, number_in_orig, j;
	size_t i;
	
	if (size < 2)
	{
		print_array(array, size);
		return;
	}
	highest = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > highest)
			highest = array[i];
	}
	count = malloc(sizeof(size_t) * (highest + 1));
	final = malloc(sizeof(int) * size);
	for (j = 0; j <= highest; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
	{
		number_in_orig = array[i];
		count[number_in_orig] += 1;
	}
	for (j = 1; j <= highest; j++)
		count[j] += count[j - 1];
	print_array(count, highest + 1);
	for (i = 0; i < size; i++)
	{
		final[count[array[i]] -1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
	       array[i] = final[i];
	free(final);
	free(count);	
}
