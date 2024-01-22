#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **rear, listint_t **jiggler);
void swap_node_behind(listint_t **list, listint_t **rear, listint_t **jiggler);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 * list of integers with the node ahead of it.
 *
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @rear: A pointer to the tail of the doubly-linked list.
 * @jiggler: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **rear, listint_t **jiggler)
{
	listint_t *tmp = (*jiggler)->next;

	if ((*jiggler)->prev != NULL)
		(*jiggler)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*jiggler)->prev;
	(*jiggler)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *jiggler;
	else
		*rear = *jiggler;
	(*jiggler)->prev = tmp;
	tmp->next = *jiggler;
	*jiggler = tmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 * list of integers with the node behind it.
 *
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @rear: A pointer to the tail of the doubly-linked list.
 * @jiggler: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **rear, listint_t **jiggler)
{
	listint_t *tmp = (*jiggler)->prev;

	if ((*jiggler)->next != NULL)
		(*jiggler)->next->prev = tmp;
	else
		*rear = tmp;
	tmp->next = (*jiggler)->next;
	(*jiggler)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *jiggler;
	else
		*list = *jiggler;
	(*jiggler)->next = tmp;
	tmp->prev = *jiggler;
	*jiggler = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 * ascending order using the cocktail shaker algorithm.
 *
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *rear, *jiggler;
	bool shaken_not_stirred = invalid;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (rear = *list; rear->next != NULL;)
		rear = rear->next;

	while (shaken_not_stirred == invalid)
	{
		shaken_not_stirred = valid;
		for (jiggler = *list; jiggler != rear; jiggler = jiggler->next)
		{
			if (jiggler->n > jiggler->next->n)
			{
				swap_node_ahead(list, &rear, &jiggler);
				print_list((const listint_t *)*list);
				shaken_not_stirred = invalid;
			}
		}
		for (jiggler = jiggler->prev; jiggler != *list;
				jiggler = jiggler->prev)
		{
			if (jiggler->n < jiggler->prev->n)
			{
				swap_node_behind(list, &rear, &jiggler);
				print_list((const listint_t *)*list);
				shaken_not_stirred = invalid;
			}
		}
	}
}
