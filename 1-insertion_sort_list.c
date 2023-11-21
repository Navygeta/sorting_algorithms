#include "sort.h"

/**
 * find_insert_pos - Finds the position to insert a node in a sorted list
 * @sorted_list: Pointer to the head of the sorted doubly linked list
 * @new_node: Node to be inserted in the sorted list
 */
void find_insert_pos(listint_t **sorted_list, listint_t *new_node)
{
	listint_t *c_nod = *sorted_list;

	/*is our list empty???*/
	if (*sorted_list == NULL || new_node->n < (*sorted_list)->n)
	{
		new_node->next = *sorted_list;
		new_node->prev = NULL;
		if (*sorted_list != NULL)
			(*sorted_list)->prev = new_node;
		*sorted_list = new_node;
		return;
	}

	while (c_nod->next != NULL && c_nod->next->n < new_node->n)
		c_nod = c_nod->next;

	new_node->prev = c_nod;
	new_node->next = c_nod->next;

	if (c_nod->next != NULL)
		c_nod->next->prev = new_node;

	c_nod->next = new_node;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of inrs in ascending order
 * @list: Pointer to the head of the unsorted doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted_list = NULL, *c_nod = *list, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (c_nod != NULL)
	{
		next_node = c_nod->next;

		/*print_list(*list);*/

		find_insert_pos(&sorted_list, c_nod);

		/*Do we need a swap???*/
		if (c_nod->prev != NULL && c_nod->n < c_nod->prev->n)
		{
			nod_swp_list(list, c_nod->prev, c_nod);
			print_list(*list);
		}

		c_nod = next_node;
	}

	*list = sorted_list;
}

/**
 * nod_swp_list - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 * @first: Pointer to the first node to be swapped
 * @second: Pointer to the second node to be swapped
 * Return: Sorted list
 */
listint_t *nod_swp_list(listint_t **list, listint_t *first, listint_t *second)
{
	listint_t *temp_prev, *temp_next;

	if (first == NULL || second == NULL || first == second)
		return (*list);

	temp_prev = first->prev;
	first->prev = second->prev;
	second->prev = temp_prev;

	if (first->prev != NULL)
		first->prev->next = second;
	else
		*list = second;

	temp_next = first->next;
	first->next = second->next;
	second->next = temp_next;

	if (first->next != NULL)
		first->next->prev = second;

	if (second->next != NULL)
		second->next->prev = first;

	if (temp_prev == NULL)
		*list = second;
	else if (second->prev == NULL)
		*list = first;

	return (*list);
}
