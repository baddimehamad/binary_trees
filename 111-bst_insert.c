#include "binary_trees.h"

/**
 * bst_insert 
 * @_tree: pointer
 * @_val: number
 *
 * Return: if the _tree NUll or the function return zero or 1.
 */
bst_t *bst_insert(bst_t **_tree, int _val)
{
	bst_t *_current, *new;

	if (_tree != NULL)
	{
		_current = *_tree;

		if (_current == NULL)
		{
			new = binary_tree_node(_current, _val);
			if (new == NULL)
				return (NULL);
			return (*_tree = new);
		}

		if (_val < _current->n)
		{
			if (_current->left != NULL)
				return (bst_insert(&_current->left, _val));

			new = binary_tree_node(_current, _val);
			if (new == NULL)
				return (NULL);
			return (_current->left = new);
		}
		if (_val > _current->n)
		{
			if (_current->right != NULL)
				return (bst_insert(&_current->right, _val));

			new = binary_tree_node(_current, _val);
			if (new == NULL)
				return (NULL);
			return (_current->right = new);
		}
	}
	return (NULL);
}
