#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 * Description: Sorts after swap
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, min_i;

	if (size < 2 || array == NULL)
		return;

	while (i < size - 1)
	{
		min_i = find_min_element(array, i, size);

		if (i != min_i)
		{
			nod_swap(array + i, array + min_i);
			print_array(array, size);
		}

		i++;
	}
}

/**
 * find_min_element - Finds the index of the minimum element in an array.
 * @array: The array of integers.
 * @start: The starting index for finding the minimum element.
 * @size: The size of the array.
 *
 * Return: Index of the minimum element.
 */
size_t find_min_element(int *array, size_t start, size_t size)
{
	size_t min_i = start, i;

	for (i = start + 1; i < size; i++)
	{
		if (array[i] < array[min_i])
			min_i = i;
	}

	return (min_i);
}

/**
 * nod_swap - Swaps the values 2 nodes in the listint_t struct
 * @first: Pointer to first node
 * @second: Pointer to second node
 */
void nod_swap(int *first, int *second)
{
	int temp = *first;

	*first = *second;
	*second = temp;
}
