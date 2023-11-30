#include "binary_trees.h"

/**
 * binary_tree_is_leaf - it check the node if its in the leaf.
 * @_node: A pointer to the node to check.
 *
 * Return: If the node is a leaf - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_leaf(const binary_tree_t *_node)
{
	if (_node == NULL || _node->left != NULL || _node->right != NULL)
		return (0);

	return (1);
}
