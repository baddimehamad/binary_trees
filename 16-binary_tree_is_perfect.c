#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *_node);
size_t depth(const binary_tree_t *_tree);
const binary_tree_t *get_leaf(const binary_tree_t *_tree);
int is_perfect_recursive(const binary_tree_t *_tree,
		size_t the_leaf_depth, size_t the_level);
int binary_tree_is_perfect(const binary_tree_t *_tree);

/**
 * is_leaf 
 * @_node: A pointer
 *
 * Return: If the _node is a leaf, 1, otherwise, 0.
 */
unsigned char is_leaf(const binary_tree_t *_node)
{
	return ((_node->left == NULL && _node->right == NULL) ? 1 : 0);
}

/**
 * depth 
 * @_tree:  pointer
 *
 * Return: The depth of _node.
 */
size_t depth(const binary_tree_t *_tree)
{
	return (_tree->parent != NULL ? 1 + depth(_tree->parent) : 0);
}

/**
 * get_leaf - Returns a leaf of a binary _tree.
 * @_tree: its the pointer to the root _node
 *
 * Return: A pointer
 */
const binary_tree_t *get_leaf(const binary_tree_t *_tree)
{
	if (is_leaf(_tree) == 1)
		return (_tree);
	return (_tree->left ? get_leaf(_tree->left) : get_leaf(_tree->right));
}

/**
 * is_perfect_recursive 
 * @_tree: pointer
 * @the_leaf_depth: number
 * @the_level: number
 *
 * Return: it return needer 0 or 1
 */
int is_perfect_recursive(const binary_tree_t *_tree,
		size_t the_leaf_depth, size_t the_level)
{
	if (is_leaf(_tree))
		return (the_level == the_leaf_depth ? 1 : 0);
	if (_tree->left == NULL || _tree->right == NULL)
		return (0);
	return (is_perfect_recursive(_tree->left, the_leaf_depth, the_level + 1) &&
		is_perfect_recursive(_tree->right, the_leaf_depth, the_level + 1));
}

/**
 * binary_tree_is_perfect 
 * @_tree: pointer
 *
 * Return: If _tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *_tree)
{
	if (_tree == NULL)
		return (0);
	return (is_perfect_recursive(_tree, depth(get_leaf(_tree)), 0));
}
