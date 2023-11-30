#include "binary_trees.h"

/**
 * binary_tree_postorder - go to the universal binary tree and result
 * @_tree: its the pointer to the root node
 * @_fun: its the pointers of the functions of each tree
 */
void binary_tree_postorder(const binary_tree_t *_tree, void (*_fun)(int))
{
	if (_tree && _fun)
	{
		binary_tree_postorder(_tree->left, _fun);
		binary_tree_postorder(_tree->right, _fun);
		_fun(_tree->n);
	}
}
