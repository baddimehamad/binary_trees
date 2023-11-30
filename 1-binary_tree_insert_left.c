#include "binary_trees.h"

/**
 * binary_tree_insert_left
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the created node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *the_new_val;

	if (parent == NULL)
		return (NULL);

	the_new_val = binary_tree_node(parent, value);
	if (the_new_val == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		the_new_val->left = parent->left;
		parent->left->parent = the_new_val;
	}
	parent->left = the_new_val;

	return (the_new_val);
}
