#include "binary_trees.h"

/**
 * array_to_bst 
 * @array: pointer
 * @the_size: number
 *
 * Return: if the v_t NUll or the function return zero or 1.
 */
bst_t *array_to_bst(int *array, size_t the_size)
{
	bst_t *v_t = NULL;
	size_t x, y;

	if (array == NULL)
		return (NULL);

	for (x = 0; x < the_size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}
		if (y == x)
		{
			if (bst_insert(&v_t, array[x]) == NULL)
				return (NULL);
		}
	}

	return (v_t);
}
