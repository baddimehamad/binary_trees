#include "binary_trees.h"

/**
 * count_h_nodes 
 * @the_root: Pointer
 *
 * Return: Number of tree nodes
 */
int count_h_nodes(binary_tree_t *the_root)
{
	if (!the_root)
		return (0);

	return (1 + count_h_nodes(the_root->left) +
		    count_h_nodes(the_root->right));
}

/**
 * heap_to_sorted_array
 * @the_heap: Pointer
 * @the_size: Pointer
 *
 * Return: Pointer to array of integeres
 */
int *heap_to_sorted_array(heap_t *the_heap, size_t *the_size)
{
	int i, nodes, *arr = NULL;

	*the_size = 0;
	if (!the_heap)
		return (NULL);

	nodes = count_h_nodes(the_heap);
	arr = malloc(sizeof(*arr) * nodes);
	if (!arr)
		return (NULL);

	*the_size = nodes;
	for (i = 0; i < nodes; i++)
		arr[i] = heap_extract(&the_heap);

	return (arr);
}
