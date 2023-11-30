#include "binary_trees.h"

/**
 * array_to_heap
 *
 * @the_array: pointer
 * @the_size: number
 * Return: pointer to the root node of the AVL the_tree
 */
heap_t *array_to_heap(int *the_array, size_t the_size)
{
	heap_t *the_tree;
	size_t x;

	the_tree = NULL;

	for (x = 0; x < the_size; x++)
	{
		heap_insert(&the_tree, the_array[x]);
	}

	return (the_tree);
}
