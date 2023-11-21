#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: The array with integers to sort
 * @size: Array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, index;
	int swap_check;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		swap_check = 0;

		for (index = 0; index < size - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				nod_swap(array + index, array + index + 1);
				swap_check = 1;
				print_array(array, size);
			}
		}

		if (swap_check == 0)
			break;
	}
}

/**
 * nod_swap - Swaps the 2 node values
 * @first: Pointer to first node
 * @second: Pointer to second node
 */
void nod_swap(int *first, int *second)
{
	int temp = *first;

	*first = *second;
	*second = temp;
}
