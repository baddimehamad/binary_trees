#include "binary_trees.h"

/**
 * binary_tree_is_root
 * @_node: A pointer to the node to check.
 *
 * Return: 0 or 1
 */
int binary_tree_is_root(const binary_tree_t *_node)
{
	if (_node == NULL || _node->parent != NULL)
		return (0);

	return (1);
}
