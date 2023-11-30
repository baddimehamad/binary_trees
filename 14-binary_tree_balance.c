#include "binary_trees.h"

/**
 * binary_tree_balance - it return the balance of the binary _tree
 * @_tree: its the pointer to the root node
 *
 * Return: if the _tree is NUll or return zero.
 */
int binary_tree_balance(const binary_tree_t *_tree)
{
	if (_tree)
		return (binary_tree_height(_tree->left) - binary_tree_height(_tree->right));

	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary _tree.
 * @_tree: A pointer to the root node of the _tree to measure the height.
 *
 * Return: If _tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *_tree)
{
	if (_tree)
	{
		size_t the_left = 0, the_right = 0;

		the_left = _tree->left ? 1 + binary_tree_height(_tree->left) : 1;
		the_right = _tree->right ? 1 + binary_tree_height(_tree->right) : 1;
		return ((the_left > the_right) ? the_left : the_right);
	}
	return (0);
}
