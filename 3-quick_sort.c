#include "sort.h"

/**
 * partition - Uses Hoare partition scheme for Quick Sort.
 * @array: The array of integers.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: Index of the pivot.
 */
int partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int key_element = array[low];
	ssize_t i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < key_element);

		do {
			j--;
		} while (array[j] > key_element);

		if (i >= j)
		{
			return (j);
		}

		nod_swap(&array[i], &array[j]);
		/*nod_swap(array, i, j);*/
		print_array(array, size);
	}
}

/**
 * qs_recursive - Recursive function for Quick Sort.
 * @array: The array of integers.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 */
void qs_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	int p_index;

	if (low < high)
	{
		p_index = partition(array, low, high, size);

		qs_recursive(array, low, p_index, size);
		qs_recursive(array, p_index + 1, high, size);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order
 *              using the Quick Sort algorithm (Hoare partition).
 * @array: The array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	print_array(array, size);

	qs_recursive(array, 0, size - 1, size);
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
