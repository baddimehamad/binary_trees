#include "binary_trees.h"

/**
 * binary_tree_sibling 
 * @_node: pointer 
 *
 * Return: if the tree NUll or the function return zero or 1.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *_node)
{
	if (_node == NULL || _node->parent == NULL)
		return (NULL);
	if (_node->parent->left == _node)
		return (_node->parent->right);
	return (_node->parent->left);
}
