#include "binary_trees.h"

size_t height(const binary_tree_t *_tree);
int balance(const binary_tree_t *_tree);
avl_t *avl_insert_recursive(avl_t **_tree, avl_t *the_parent,
		avl_t **the_new_v, int _val);
avl_t *avl_insert(avl_t **_tree, int _val);

/**
 * height 
 * @_tree: pointer
 *
 * Return: If _tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *_tree)
{
	if (_tree != NULL)
	{
		size_t l = 0, r = 0;

		l = _tree->left ? 1 + binary_tree_height(_tree->left) : 1;
		r = _tree->right ? 1 + binary_tree_height(_tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance 
 * @_tree: pointer
 *
 * Return: If _tree is NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *_tree)
{
	return (_tree != NULL ? height(_tree->left) - height(_tree->right) : 0);
}

/**
 * avl_insert_recursive 
 * @_tree: pointer
 * @the_parent: pointer
 * @the_new_v: pointer
 * @_val: The value to insert into the AVL tree.
 *
 * Return: A pointer to the the_new_v root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **_tree, avl_t *the_parent,
		avl_t **the_new_v, int _val)
{
	int the_binary_factor;

	if (*_tree == NULL)
		return (*the_new_v = binary_tree_node(the_parent, _val));

	if ((*_tree)->n > _val)
	{
		(*_tree)->left = avl_insert_recursive(&(*_tree)->left, *_tree, the_new_v, _val);
		if ((*_tree)->left == NULL)
			return (NULL);
	}
	else if ((*_tree)->n < _val)
	{
		(*_tree)->right = avl_insert_recursive(&(*_tree)->right, *_tree, the_new_v, _val);
		if ((*_tree)->right == NULL)
			return (NULL);
	}
	else
		return (*_tree);

	the_binary_factor = balance(*_tree);
	if (the_binary_factor > 1 && (*_tree)->left->n > _val)
		*_tree = binary_tree_rotate_right(*_tree);
	else if (the_binary_factor < -1 && (*_tree)->right->n < _val)
		*_tree = binary_tree_rotate_left(*_tree);
	else if (the_binary_factor > 1 && (*_tree)->left->n < _val)
	{
		(*_tree)->left = binary_tree_rotate_left((*_tree)->left);
		*_tree = binary_tree_rotate_right(*_tree);
	}
	else if (the_binary_factor < -1 && (*_tree)->right->n > _val)
	{
		(*_tree)->right = binary_tree_rotate_right((*_tree)->right);
		*_tree = binary_tree_rotate_left(*_tree);
	}

	return (*_tree);
}

/**
 * avl_insert 
 * @_tree: pointer
 * @_val: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **_tree, int _val)
{
	avl_t *the_new_v = NULL;

	if (_tree == NULL)
		return (NULL);
	if (*_tree == NULL)
	{
		*_tree = binary_tree_node(NULL, _val);
		return (*_tree);
	}
	avl_insert_recursive(_tree, *_tree, &the_new_v, _val);
	return (the_new_v);
}
