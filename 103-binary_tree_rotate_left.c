#include "binary_trees.h"

/**
 * binary_tree_rotate_left 
 * @_tree: pointer
 *
 * Return: pointer
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *_tree)
{
	binary_tree_t *the_pivot, *temp;

	if (_tree == NULL || _tree->right == NULL)
		return (NULL);

	the_pivot = _tree->right;
	temp = the_pivot->left;
	the_pivot->left = _tree;
	_tree->right = temp;
	if (temp != NULL)
		temp->parent = _tree;
	temp = _tree->parent;
	_tree->parent = the_pivot;
	the_pivot->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == _tree)
			temp->left = the_pivot;
		else
			temp->right = the_pivot;
	}

	return (the_pivot);
}
