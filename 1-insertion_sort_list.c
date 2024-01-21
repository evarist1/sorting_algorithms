#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @d: A pointer to the head of the doubly-linked list.
 * @q1: A pointer to the first node to swap.
 * @q2: The second node to swap.
 */
void swap_nodes(listint_t **d, listint_t **q1, listint_t *q2)
{
	(*q1)->next = q2->next;
	if (q2->next != NULL)
		q2->next->prev = *q1;
	q2->prev = (*q1)->prev;
	q2->next = *q1;
	if ((*q1)->prev != NULL)
		(*q1)->prev->next = q2;
	else
		*d = q2;
	(*q1)->prev = q2;
	*q1 = q2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the insertion sort algorithm.
 *
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterate, *add, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterate = (*list)->next; iterate != NULL; iterate = tmp)
	{
		tmp = iterate->next;
		add = iterate->prev;
		while (add != NULL && iterate->n < add->n)
		{
			swap_nodes(list, &add, iterate);
			print_list((const listint_t *)*list);
		}
	}
}
