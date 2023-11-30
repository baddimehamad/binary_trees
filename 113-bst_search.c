#include "binary_trees.h"

/**
 * bst_search 
 * @_tree: pointer
 * @the_value: number
 *
 * Return: if the _tree NUll or the function return zero or 1.
 */
bst_t *bst_search(const bst_t *_tree, int the_value)
{
	if (_tree != NULL)
	{
		if (_tree->n == the_value)
			return ((bst_t *)_tree);
		if (_tree->n > the_value)
			return (bst_search(_tree->left, the_value));
		return (bst_search(_tree->right, the_value));
	}
	return (NULL);
}
