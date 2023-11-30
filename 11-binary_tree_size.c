#include "binary_trees.h"

/**
 * binary_tree_size
 * @_tree: its the pointer to the root node
 *
 * Return: number
 */
size_t binary_tree_size(const binary_tree_t *_tree)
{
	size_t _val = 0;

	if (_tree)
	{
		_val += 1;
		_val += binary_tree_size(_tree->left);
		_val += binary_tree_size(_tree->right);
	}
	return (_val);
}
