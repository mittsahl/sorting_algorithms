#include "sort.h"

/**
 * insertion_sort_list - Sorts an list of integers using insertion sort
 *
 * @list: The list to be printed and sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;

	if (!list || !(*list) || !(*list)->next)
		return;
	curr = (*list)->next;

	while (curr)
	{
		while((curr->prev != NULL) && (curr->prev->n > curr->n))
		{
			curr->prev->next = curr->next;
			if (curr->next)
				curr->next->prev = curr->prev;
			curr->next = curr->prev;
			curr->prev = curr->prev->prev;
			curr->next->prev = curr;
		
			if (curr->prev == NULL)
				*list = curr;
			else
				curr->prev->next = curr;

			print_list(*list);
		}
		curr = curr->next;
	}
}