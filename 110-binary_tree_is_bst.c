#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper 
 * @temp: pointer 
 * @the_low: number
 * @the_hight: number
 *
 * Return: If the temp is a valid BST, 1, otherwise, 0.
 */
int is_bst_helper(const binary_tree_t *temp, int the_low, int the_hight)
{
	if (temp != NULL)
	{
		if (temp->n < the_low || temp->n > the_hight)
			return (0);
		return (is_bst_helper(temp->left, the_low, temp->n - 1) &&
			is_bst_helper(temp->right, temp->n + 1, the_hight));
	}
	return (1);
}

/**
 * binary_tree_is_bst 
 * @temp: pointer
 *
 * Return: 1 if temp is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *temp)
{
	if (temp == NULL)
		return (0);
	return (is_bst_helper(temp, INT_MIN, INT_MAX));
}
