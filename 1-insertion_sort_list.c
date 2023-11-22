#include "sort.h"

/**
 * move_a_node - Moves a node to its correct position in a sorted list
 * @list: Pointer to the head of the doubly linked list
 * @node: Node to be moved
 */
void move_a_node(listint_t **list, listint_t *node)
{
	listint_t *tmp_nod = node->prev;

	/* let's unlink node from the list */
	if (node->next != NULL)
		node->next->prev = tmp_nod;
	tmp_nod->next = node->next;

	/* Now insert node before tmp_nod */
	node->prev = tmp_nod->prev;
	node->next = tmp_nod;
	if (tmp_nod->prev != NULL)
		tmp_nod->prev->next = node;
	else
		*list = node;
	tmp_nod->prev = node;
	print_list((const listint_t *)*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of inrs in ascending order
 * @list: Pointer to the head of the unsorted doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *c_nod = NULL, *next_node = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	c_nod = (*list)->next;

	while (c_nod != NULL)
	{
		next_node = c_nod->next;
		while (c_nod->prev != NULL && c_nod->n < c_nod->prev->n)
		{
			move_a_node(list, c_nod);
		}
		c_nod = next_node;
	}
}
