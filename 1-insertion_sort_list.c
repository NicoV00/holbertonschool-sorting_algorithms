#include "sort.h"

/**
 * insertion_sort_list - Sorting a list bassed off of insertion.
 * @list: Double linked list.
 * Return: Sorted list.
 */
 void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;
			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			prev = current->prev;
            print_list(*list);
			
		}
		current = next;
	}
}