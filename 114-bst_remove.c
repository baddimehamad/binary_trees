#include "binary_trees.h"

bst_t *inorder_successor(bst_t *the_root);
bst_t *bst_delete(bst_t *the_root, bst_t *_node);
bst_t *bst_remove_recursive(bst_t *the_root, bst_t *_node, int the_v);
bst_t *bst_remove(bst_t *the_root, int the_v);

/**
 * inorder_successor
 * @the_root: pointer
 *
 * Return: it return's a number
 */
bst_t *inorder_successor(bst_t *the_root)
{
	while (the_root->left != NULL)
		the_root = the_root->left;
	return (the_root);
}

/**
 * bst_delete 
 * @the_root: pointer
 * @_node:  pointer
 *
 * Return: pointer
 */
bst_t *bst_delete(bst_t *the_root, bst_t *_node)
{
	bst_t *the_parent = _node->parent, *successor = NULL;

	if (_node->left == NULL)
	{
		if (the_parent != NULL && the_parent->left == _node)
			the_parent->left = _node->right;
		else if (the_parent != NULL)
			the_parent->right = _node->right;
		if (_node->right != NULL)
			_node->right->parent = the_parent;
		free(_node);
		return (the_parent == NULL ? _node->right : the_root);
	}

	if (_node->right == NULL)
	{
		if (the_parent != NULL && the_parent->left == _node)
			the_parent->left = _node->left;
		else if (the_parent != NULL)
			the_parent->right = _node->left;
		if (_node->left != NULL)
			_node->left->parent = the_parent;
		free(_node);
		return (the_parent == NULL ? _node->left : the_root);
	}

	successor = inorder_successor(_node->right);
	_node->n = successor->n;

	return (bst_delete(the_root, successor));
}

/**
 * bst_remove_recursive 
 * @the_root: pointer
 * @_node: pointer
 * @the_v: The the_v to remove from the BST.
 *
 * Return: pointer.
 */
bst_t *bst_remove_recursive(bst_t *the_root, bst_t *_node, int the_v)
{
	if (_node != NULL)
	{
		if (_node->n == the_v)
			return (bst_delete(the_root, _node));
		if (_node->n > the_v)
			return (bst_remove_recursive(the_root, _node->left, the_v));
		return (bst_remove_recursive(the_root, _node->right, the_v));
	}
	return (NULL);
}

/**
 * bst_remove 
 * @the_root: pointer
 * @the_v: The the_v to remove in the BST.
 *
 * Return: pointer
 *
 */
bst_t *bst_remove(bst_t *the_root, int the_v)
{
	return (bst_remove_recursive(the_root, the_root, the_v));
}
