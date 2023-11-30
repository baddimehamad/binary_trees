#include "binary_trees.h"

/**
 * height 
 *
 * @_tree: pointer
 * Return: height
 */
int height(const binary_tree_t *_tree)
{
	int left = 0;
	int right = 0;

	if (_tree == NULL)
		return (-1);

	left = height(_tree->left);
	right = height(_tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * binary_tree_is_perfect 
 *
 * @_tree: pointer
 * Return: 1 if _tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *_tree)
{
	if (_tree && height(_tree->left) == height(_tree->right))
	{
		if (height(_tree->left) == -1)
			return (1);

		if ((_tree->left && !((_tree->left)->left) && !((_tree->left)->right))
		    && (_tree->right && !((_tree->right)->left) && !((_tree->right)->right)))
			return (1);

		if (_tree && _tree->left && _tree->right)
			return (binary_tree_is_perfect(_tree->left) &&
				binary_tree_is_perfect(_tree->right));
	}

	return (0);
}

/**
 * swap 
 *
 * @the_arg_node: parent
 * @the_arg_child: child
 * Return: no return
 */
void swap(heap_t **the_arg_node, heap_t **the_arg_child)
{
	heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
	int left_right;

	node = *the_arg_node, child = *the_arg_child;
	if (child->n > node->n)
	{
		if (child->left)
			child->left->parent = node;
		if (child->right)
			child->right->parent = node;
		if (node->left == child)
			node_child = node->right, left_right = 0;
		else
			node_child = node->left, left_right = 1;
		node_left = child->left, node_right = child->right;
		if (left_right == 0)
		{
			child->right = node_child;
			if (node_child)
				node_child->parent = child;
			child->left = node;
		}
		else
		{
			child->left = node_child;
			if (node_child)
				node_child->parent = child;
			child->right = node;
		}
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = child;
			else
				node->parent->right = child;
		}
		parent = node->parent, child->parent = parent;
		node->parent = child, node->left = node_left;
		node->right = node_right, *the_arg_node = child;
	}
}

/**
 * heap_insert
 * @the_value: the_value to be inserted
 * @the_root: root
 * Return: pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **the_root, int the_value)
{
	heap_t *new_node;

	if (*the_root == NULL)
	{
		*the_root = binary_tree_node(NULL, the_value);
		return (*the_root);
	}

	if (binary_tree_is_perfect(*the_root) || !binary_tree_is_perfect((*the_root)->left))
	{
		if ((*the_root)->left)
		{
			new_node = heap_insert(&((*the_root)->left), the_value);
			swap(the_root, &((*the_root)->left));
			return (new_node);
		}
		else
		{
			new_node = (*the_root)->left = binary_tree_node(*the_root, the_value);
			swap(the_root, &((*the_root)->left));
			return (new_node);
		}
	}

	if ((*the_root)->right)
	{
		new_node = heap_insert(&((*the_root)->right), the_value);
		swap(the_root, (&(*the_root)->right));
		return (new_node);
	}
	else
	{
		new_node = (*the_root)->right = binary_tree_node(*the_root, the_value);
		swap(the_root, &((*the_root)->right));
		return (new_node);
	}

	return (NULL);
}
