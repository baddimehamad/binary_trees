#include "binary_trees.h"

/**
 * binary_tree_insert_right
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *the_new_val;

	if (parent == NULL)
		return (NULL);

	the_new_val = binary_tree_node(parent, value);
	if (the_new_val == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		the_new_val->right = parent->right;
		parent->right->parent = the_new_val;
	}
	parent->right = the_new_val;

	return (the_new_val);
}
