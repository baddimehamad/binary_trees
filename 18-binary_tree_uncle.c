#include "binary_trees.h"

/**
 * binary_tree_uncle - this funtion find the uncle of the binary tree
 * @_node: A pointer to the _node to find the uncle of.
 *
 * Return: if the tree NUll or the function return zero or 1.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *_node)
{
	if (_node == NULL ||
	    _node->parent == NULL ||
	    _node->parent->parent == NULL)
		return (NULL);
	if (_node->parent->parent->left == _node->parent)
		return (_node->parent->parent->right);
	return (_node->parent->parent->left);
}
