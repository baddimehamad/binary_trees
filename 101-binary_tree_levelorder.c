#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *_node);
void free_queue(levelorder_queue_t *the_head);
void pint_push(binary_tree_t *_node, levelorder_queue_t *the_head,
		levelorder_queue_t **the_tail, void (*_fun)(int));
void pop(levelorder_queue_t **the_head);
void binary_tree_levelorder(const binary_tree_t *_tree, void (*_fun)(int));

/**
 * create_node 
 * @_node: Tnumber.
 *
 * Return: if the _tree NUll or the function return zero or 1..
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
 * free_queue - Frees a levelorder_queue_t queue.
 * @the_head: A pointer to the the_head of the queue.
 */
void free_queue(levelorder_queue_t *the_head)
{
	levelorder_queue_t *tmp;

	while (the_head != NULL)
	{
		tmp = the_head->next;
		free(the_head);
		the_head = tmp;
	}
}

/**
 * pint_push 
 * @_node: The binary _tree _node to print and push.
 * @the_head: A double pointer to the the_head of the queue.
 * @the_tail: A double pointer to the the_tail of the queue.
 * @_fun: A pointer to the function to call on @_node.
 *
 * Description: if the _tree NUll or the function return zero or 1..
 */
void pint_push(binary_tree_t *_node, levelorder_queue_t *the_head,
		levelorder_queue_t **the_tail, void (*_fun)(int))
{
	levelorder_queue_t *the_new_v;

	_fun(_node->n);
	if (_node->left != NULL)
	{
		the_new_v = create_node(_node->left);
		if (the_new_v == NULL)
		{
			free_queue(the_head);
			exit(1);
		}
		(*the_tail)->next = the_new_v;
		*the_tail = the_new_v;
	}
	if (_node->right != NULL)
	{
		the_new_v = create_node(_node->right);
		if (the_new_v == NULL)
		{
			free_queue(the_head);
			exit(1);
		}
		(*the_tail)->next = the_new_v;
		*the_tail = the_new_v;
	}
}

/**
 * pop 
 * @the_head: the double pointer of the the_head to the queue.
 */
void pop(levelorder_queue_t **the_head)
{
	levelorder_queue_t *tmp;

	tmp = (*the_head)->next;
	free(*the_head);
	*the_head = tmp;
}

/**
 * binary_tree_levelorder - Traverses a binary _tree using
 *                          level-order traversal.
 * @_tree: A pointer to the root _node of the _tree to traverse.
 * @_fun: A pointer to a function to call for each _node.
 */
void binary_tree_levelorder(const binary_tree_t *_tree, void (*_fun)(int))
{
	levelorder_queue_t *the_head, *the_tail;

	if (_tree == NULL || _fun == NULL)
		return;

	the_head = the_tail = create_node((binary_tree_t *)_tree);
	if (the_head == NULL)
		return;

	while (the_head != NULL)
	{
		pint_push(the_head->node, the_head, &the_tail, _fun);
		pop(&the_head);
	}
}
