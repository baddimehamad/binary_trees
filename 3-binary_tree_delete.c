#include "binary_trees.h"

/**
 * binary_tree_delete - for Delete the binary tree.
 * @_tree: the pointer to root node of the tree that will be deleted.
 */
void binary_tree_delete(binary_tree_t *_tree)
{
	if (_tree != NULL)
	{
		binary_tree_delete(_tree->left);
		binary_tree_delete(_tree->right);
		free(_tree);
	}
}
