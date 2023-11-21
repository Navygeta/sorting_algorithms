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
