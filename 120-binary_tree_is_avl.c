#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *the_tree);
int is_avl_helper(const binary_tree_t *the_tree, int the_low, int the_hight);
int binary_tree_is_avl(const binary_tree_t *the_tree);

/**
 * height
 * @the_tree: pointer
 *
 * Return: If the_tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *the_tree)
{
	if (the_tree)
	{
		size_t l = 0, r = 0;

		l = the_tree->left ? 1 + height(the_tree->left) : 1;
		r = the_tree->right ? 1 + height(the_tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_avl_helper 
 * @the_tree: pointer
 * @the_low: number
 * @the_hight: number
 *
 * Return: If the the_tree is a valid AVL the_tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *the_tree, int the_low, int the_hight)
{
	size_t _tg, _ri, difference;

	if (the_tree != NULL)
	{
		if (the_tree->n < the_low || the_tree->n > the_hight)
			return (0);
		_tg = height(the_tree->left);
		_ri = height(the_tree->right);
		difference = _tg > _ri ? _tg - _ri : _ri - _tg;
		if (difference > 1)
			return (0);
		return (is_avl_helper(the_tree->left, the_low, the_tree->n - 1) &&
			is_avl_helper(the_tree->right, the_tree->n + 1, the_hight));
	}
	return (1);
}

/**
 * binary_tree_is_avl 
 * @the_tree: pointer
 *
 * Return: 1 if the_tree is a valid AVL the_tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *the_tree)
{
	if (the_tree == NULL)
		return (0);
	return (is_avl_helper(the_tree, INT_MIN, INT_MAX));
}
