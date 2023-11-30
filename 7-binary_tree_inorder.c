#include "binary_trees.h"

/**
 * binary_tree_inorder - go to the universal binary tree and result
 * @_tree: its the pointer to the root node
 * @_fun: its the pointers of the functions of each tree
 */
void binary_tree_inorder(const binary_tree_t *_tree, void (*_fun)(int))
{
	if (_tree && _fun)
	{
		binary_tree_inorder(_tree->left, _fun);
		_fun(_tree->n);
		binary_tree_inorder(_tree->right, _fun);
	}
}
