#include "binary_trees.h"

/**
 * count_heap_nodes 
 * @_root: Pointer 
 *
 * Return: Number of tree nodes
 */
int count_heap_nodes(binary_tree_t *_root)
{
	if (!_root)
		return (0);

	return (1 + count_heap_nodes(_root->left) +
		    count_heap_nodes(_root->right));
}


/**
 * bubble_down 
 * @_parent: Pointer 
 */
void bubble_down(heap_t *_parent)
{
	int temp;
	heap_t *max_child = NULL;

	if (!_parent)
		return;

	while (_parent && _parent->left)
	{
		max_child = _parent->left;

		if (_parent->right && _parent->right->n > _parent->left->n)
			max_child = _parent->right;

		if (max_child->n > _parent->n)
		{
			temp = _parent->n;
			_parent->n = max_child->n;
			max_child->n = temp;
		}

		_parent = max_child;
	}
}


/**
 * get_parent 
 * @_root: Pointer
 * @the_index: Index
 * @the_p_index: Index
 *
 * Return: Pointer to heap's node
 */
heap_t *get_parent(heap_t *_root, int the_index, int the_p_index)
{
	heap_t *left = NULL, *right = NULL;

	if (!_root || the_index > the_p_index)
		return (NULL);

	if (the_index == the_p_index)
		return (_root);

	left = get_parent(_root->left, the_index * 2 + 1, the_p_index);
	if (left)
		return (left);

	right = get_parent(_root->right, the_index * 2 + 2, the_p_index);
	if (right)
		return (right);

	return (NULL);
}


/**
 * remove_last_node
 * @_root: pointer
 * @_parent: Pointer
 */
void remove_last_node(heap_t **_root, heap_t *_parent)
{
	if (_parent == *_root && !_parent->left)
	{
		free(*_root);
		*_root = NULL;

		return;
	}

	if (_parent->right)
	{
		(*_root)->n = _parent->right->n;
		free(_parent->right);
		_parent->right = NULL;
	}
	else if (_parent->left)
	{
		(*_root)->n = _parent->left->n;
		free(_parent->left);
		_parent->left = NULL;
	}

	bubble_down(*_root);
}


/**
 * heap_extract 
 * @_root: pointer
 *
 * Return: Heap's max value
 */
int heap_extract(heap_t **_root)
{
	int nodes, the_p_index = 0, max_val = 0;
	heap_t *_parent;

	if (!_root || !(*_root))
		return (0);

	max_val = (*_root)->n;
	nodes = count_heap_nodes(*_root);

	the_p_index = (nodes - 2) / 2;
	_parent = get_parent(*_root, 0, the_p_index);

	remove_last_node(_root, _parent);

	return (max_val);
}
