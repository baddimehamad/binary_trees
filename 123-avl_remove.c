#include "binary_trees.h"

/**
 * bal 
 * @the_tree: the_tree of the binary
 * Return: balanced factor
 */
void bal(avl_t **the_tree)
{
	int bval;

	if (the_tree == NULL || *the_tree == NULL)
		return;
	if ((*the_tree)->left == NULL && (*the_tree)->right == NULL)
		return;
	bal(&(*the_tree)->left);
	bal(&(*the_tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*the_tree);
	if (bval > 1)
		*the_tree = binary_tree_rotate_right((binary_tree_t *)*the_tree);
	else if (bval < -1)
		*the_tree = binary_tree_rotate_left((binary_tree_t *)*the_tree);
}
/**
 * successor 
 * @node: check the the_tree
 * Return: the min the_value of this the_tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 *remove_type 
 *@the_root: the node that will be removed
 *Return: 0 if it has no children or other the_value if it has
 */
int remove_type(bst_t *the_root)
{
	int new_value = 0;

	if (!the_root->left && !the_root->right)
	{
		if (the_root->parent->right == the_root)
			the_root->parent->right = NULL;
		else
			the_root->parent->left = NULL;
		free(the_root);
		return (0);
	}
	else if ((!the_root->left && the_root->right) || (!the_root->right && the_root->left))
	{
		if (!the_root->left)
		{
			if (the_root->parent->right == the_root)
				the_root->parent->right = the_root->right;
			else
				the_root->parent->left = the_root->right;
			the_root->right->parent = the_root->parent;
		}
		if (!the_root->right)
		{
			if (the_root->parent->right == the_root)
				the_root->parent->right = the_root->left;
			else
				the_root->parent->left = the_root->left;
			the_root->left->parent = the_root->parent;
		}
		free(the_root);
		return (0);
	}
	else
	{
		new_value = successor(the_root->right);
		the_root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove 
 * @the_root: the main the_tree
 * @the_value: the value that will be removed
 * Return: the the_tree changed
 */
bst_t *bst_remove(bst_t *the_root, int the_value)
{
	int type = 0;

	if (the_root == NULL)
		return (NULL);
	if (the_value < the_root->n)
		bst_remove(the_root->left, the_value);
	else if (the_value > the_root->n)
		bst_remove(the_root->right, the_value);
	else if (the_value == the_root->n)
	{
		type = remove_type(the_root);
		if (type != 0)
			bst_remove(the_root->right, type);
	}
	else
		return (NULL);
	return (the_root);
}

/**
 * avl_remove 
 * @the_root: the_root of the the_tree
 * @the_value: node with this value to remove
 * Return: the the_tree changed
 */
avl_t *avl_remove(avl_t *the_root, int the_value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) the_root, the_value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
