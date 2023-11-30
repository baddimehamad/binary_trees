#include "binary_trees.h"

/**
 * array_to_avl 
 * @the_array: pointer
 * @the_size: number
 *
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */
avl_t *array_to_avl(int *the_array, size_t the_size)
{
	avl_t *the_tree = NULL;
	size_t x, y;

	if (the_array == NULL)
		return (NULL);

	for (x = 0; x < the_size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (the_array[y] == the_array[x])
				break;
		}
		if (y == x)
		{
			if (avl_insert(&the_tree, the_array[x]) == NULL)
				return (NULL);
		}
	}

	return (the_tree);
}
