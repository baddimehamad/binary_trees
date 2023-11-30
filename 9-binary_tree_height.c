#include "binary_trees.h"

/**
 * binary_tree_height
 * @_tree: its the pointer to the root node
 *
 * Return: null or 0
 */
size_t binary_tree_height(const binary_tree_t *_tree)
{
	if (_tree)
	{
		size_t l = 0, r = 0;

		l = _tree->left ? 1 + binary_tree_height(_tree->left) : 0;
		r = _tree->right ? 1 + binary_tree_height(_tree->right) : 0;
		return ((l > r) ? l : r);
	}
	return (0);
}
