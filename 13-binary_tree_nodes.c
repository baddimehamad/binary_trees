#include "binary_trees.h"

/**
 * binary_tree_nodes - it count the number of childs in the binary tree
 * @_tree: its the pointer to the root node
 *
 * Return: it return's null or zero.
 */
size_t binary_tree_nodes(const binary_tree_t *_tree)
{
	size_t _val = 0;

	if (_tree)
	{
		_val += (_tree->left || _tree->right) ? 1 : 0;
		_val += binary_tree_nodes(_tree->left);
		_val += binary_tree_nodes(_tree->right);
	}
	return (_val);
}
