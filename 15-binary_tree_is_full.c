#include "binary_trees.h"

/**
 * is_full_recursive - it check of the binary trre if fuul or emty
 * @_tree: its the pointer to the root node
 *
 * Return: if the tree NUll or the function return zero or 1.
 */
int is_full_recursive(const binary_tree_t *_tree)
{
	if (_tree != NULL)
	{
		if ((_tree->left != NULL && _tree->right == NULL) ||
		    (_tree->left == NULL && _tree->right != NULL) ||
		    is_full_recursive(_tree->left) == 0 ||
		    is_full_recursive(_tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @_tree: A pointer to the root node of the tree to check.
 *
 * Return: if the tree NUll or the function return zero or one.
 */
int binary_tree_is_full(const binary_tree_t *_tree)
{
	if (_tree == NULL)
		return (0);
	return (is_full_recursive(_tree));
}
