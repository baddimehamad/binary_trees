#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: pointer to the  parent of the node.
 * @value: The value of the new node.
 *
 * Return: null
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *_n_v;

	_n_v = malloc(sizeof(binary_tree_t));
	if (_n_v == NULL)
		return (NULL);

	_n_v->n = value;
	_n_v->parent = parent;
	_n_v->left = NULL;
	_n_v->right = NULL;

	return (_n_v);
}
