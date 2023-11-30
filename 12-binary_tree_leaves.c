#include "binary_trees.h"

/**
 * binary_tree_leaves
 * @_tree: its the pointer to the root node
 *
 * Return: number
 */
size_t binary_tree_leaves(const binary_tree_t *_tree)
{
	size_t the_leaves = 0;

	if (_tree)
	{
		the_leaves += (!_tree->left && !_tree->right) ? 1 : 0;
		the_leaves += binary_tree_leaves(_tree->left);
		the_leaves += binary_tree_leaves(_tree->right);
	}
	return (the_leaves);
}
