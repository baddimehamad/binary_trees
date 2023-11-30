#include "binary_trees.h"

/**
 * binary_tree_rotate_right 
 * @_tree: pointer
 *
 * Return: pointer
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *_tree)
{
	binary_tree_t *the_pivot, *temp;

	if (_tree == NULL || _tree->left == NULL)
		return (NULL);

	the_pivot = _tree->left;
	temp = the_pivot->right;
	the_pivot->right = _tree;
	_tree->left = temp;
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
