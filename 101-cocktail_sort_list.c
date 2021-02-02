#include "sort.h"

/**
 * cocktail_sort_list - cocktail shaker sorts a doubly linked list
 * Return: void
 * @list: head of the linked list
 */

void cocktail_sort_list(listint_t **list)
{
	int swp = 1, length = 0, i;
	listint_t *tmp;

	if (list == NULL)
		return;
	tmp = *list;
	
	while (tmp)
	{
		tmp = tmp->next;
		length++;
	}
	tmp = *list;
	while (swp == 1)
	{
		swp = 0;
		for (length--, i = 0; i < length; i++)
		{
			if (tmp->n > tmp->next->n)
			{
				swap(&tmp, list);
				swp = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (swp == 0)
			return;
		swp = 0;
		tmp = tmp->prev;
		for (length--, i = 0; i < length; i++)
		{
			if (tmp->n < tmp->prev->n)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				tmp->next = tmp->prev;
				tmp->prev = tmp->next->prev;
				tmp->next->prev = tmp;
				if (tmp->prev == NULL)
					*list = tmp;
				else
					tmp->prev->next = tmp;
				swp = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
		if (swp == 0)
			return;
		tmp =tmp->next;
	}
}

/**
 * swap - swaps a linked list node with the next one
 * Return: void;
 * @list: head of the linked list
 * @tmp: node to swap with next
 */

void swap(listint_t **tmp, listint_t **list)
{
	(*tmp)->next->prev = (*tmp)->prev;
	if ((*tmp)->prev)
		(*tmp)->prev->next = (*tmp)->next;
	(*tmp)->prev = (*tmp)->next;
	(*tmp)->next = (*tmp)->next->next;
	if ((*tmp)->next)
		(*tmp)->next->prev = (*tmp);
	(*tmp)->prev->next = (*tmp);
	if ((*tmp)->prev->prev == NULL)	
		*list = (*tmp)->prev;
}		
