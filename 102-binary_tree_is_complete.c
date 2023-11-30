#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *_node);
void free_queue(levelorder_queue_t *_head);
void push(binary_tree_t *_node, levelorder_queue_t *_head,
		levelorder_queue_t **the_tail);
void pop(levelorder_queue_t **_head);
int binary_tree_is_complete(const binary_tree_t *_tree);

/**
 * create_node 
 * @_node: The binary _tree _node for the the_new_v _node to contain.
 *
 * Return: nullor pointer
 */
levelorder_queue_t *create_node(binary_tree_t *_node)
{
	levelorder_queue_t *the_new_v;

	the_new_v = malloc(sizeof(levelorder_queue_t));
	if (the_new_v == NULL)
		return (NULL);

	the_new_v->node = _node;
	the_new_v->next = NULL;

	return (the_new_v);
}

/**
 * free_queue 
 * @_head:pointer
 */
void free_queue(levelorder_queue_t *_head)
{
	levelorder_queue_t *temp;

	while (_head != NULL)
	{
		temp = _head->next;
		free(_head);
		_head = temp;
	}
}

/**
 * push 
 * @_node: The binary _tree _node to print and push.
 * @_head: pointer
 * @the_tail: pointer
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *_node, levelorder_queue_t *_head,
		levelorder_queue_t **the_tail)
{
	levelorder_queue_t *the_new_v;

	the_new_v = create_node(_node);
	if (the_new_v == NULL)
	{
		free_queue(_head);
		exit(1);
	}
	(*the_tail)->next = the_new_v;
	*the_tail = the_new_v;
}

/**
 * pop 
 * @_head: pointer
 */
void pop(levelorder_queue_t **_head)
{
	levelorder_queue_t *temp;

	temp = (*_head)->next;
	free(*_head);
	*_head = temp;
}

/**
 * binary_tree_is_complete
 * @_tree: A pointer to the root _node of the _tree to traverse.
 *
 * Return: it retun null or zero or one
 */
int binary_tree_is_complete(const binary_tree_t *_tree)
{
	levelorder_queue_t *_head, *the_tail;
	unsigned char flag = 0;

	if (_tree == NULL)
		return (0);

	_head = the_tail = create_node((binary_tree_t *)_tree);
	if (_head == NULL)
		exit(1);

	while (_head != NULL)
	{
		if (_head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(_head);
				return (0);
			}
			push(_head->node->left, _head, &the_tail);
		}
		else
			flag = 1;
		if (_head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(_head);
				return (0);
			}
			push(_head->node->right, _head, &the_tail);
		}
		else
			flag = 1;
		pop(&_head);
	}
	return (1);
}
