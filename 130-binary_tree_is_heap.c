#include "binary_trees.h"

/**
 * binary_tree_size 
 *
 * @the_tree: the_tree root
 * Return: size of the tree or 0 if the_tree is NULL;
 */
size_t binary_tree_size(const binary_tree_t *the_tree)
{
	if (the_tree == NULL)
		return (0);

	return (binary_tree_size(the_tree->left) + binary_tree_size(the_tree->right) + 1);
}

/**
 * tree_is_complete 
 *
 * @the_tree: pointer
 * @x: index
 * @current_nodes: number 
 * Return: 1 if tree is complete, 0 otherwise
 */
int tree_is_complete(const binary_tree_t *the_tree, int x, int current_nodes)
{
	if (the_tree == NULL)
		return (1);

	if (x >= current_nodes)
		return (0);

	return (tree_is_complete(the_tree->left, (2 * x) + 1, current_nodes) &&
		tree_is_complete(the_tree->right, (2 * x) + 2, current_nodes));
}


/**
 * binary_tree_is_complete
 *
 * @the_tree: root
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *the_tree)
{
	size_t current_nodes;

	if (the_tree == NULL)
		return (0);

	current_nodes = binary_tree_size(the_tree);

	return (tree_is_complete(the_tree, 0, current_nodes));
}

/**
 * check_parent 
 *
 * @the_tree: pointer to the node
 * Return: 1 if parent has a greater value, 0 otherwise
 */
int check_parent(const binary_tree_t *the_tree)
{
	if (the_tree == NULL)
		return (1);

	if (the_tree->n > the_tree->parent->n)
		return (0);

	return (check_parent(the_tree->left) && check_parent(the_tree->right));
}

/**
 * binary_tree_is_heap 
 *
 * @the_tree: pointer
 * Return: 1 if the_tree is a Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *the_tree)
{
	if (!binary_tree_is_complete(the_tree))
		return (0);

	return (check_parent(the_tree->left) && check_parent(the_tree->right));
}
