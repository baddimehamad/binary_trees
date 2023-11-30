#include "binary_trees.h"

/**
 * struct node_s
 * @_node: const
 * @next: points
 */
typedef struct node_s
{
	const binary_tree_t *_node;
	struct node_s *next;
} ll;

ll *append(ll *the_head, const binary_tree_t *_binary_node);
void free_list(ll *the_head);
ll *get_children(ll *the_head, const binary_tree_t *the_parent);
void levels_rec(ll *the_head, void (*_fun)(int));

/**
 * binary_tree_levelorder
 * @_tree: Pointer
 * @_fun: Pointer
 */
void binary_tree_levelorder(const binary_tree_t *_tree, void (*_fun)(int))
{
	ll *the_children = NULL;

	_fun(_tree->n);
	the_children = get_children(the_children, _tree);
	levels_rec(the_children, _fun);

	free_list(the_children);
}

/**
 * levels_rec 
 * @the_head: Pointer
 * @_fun: Pointer
 */
void levels_rec(ll *the_head, void (*_fun)(int))
{
	ll *the_children = NULL, *curr = NULL;

	if (!the_head)
		return;
	for (curr = the_head; curr != NULL; curr = curr->next)
	{
		_fun(curr->_node->n);
		the_children = get_children(the_children, curr->_node);
	}
	levels_rec(the_children, _fun);
	free_list(the_children);
}

/**
 * get_children
 * @the_head: Pointer
 * @the_parent: Pointer
 * Return: Pointer to the_head of linked list of the_children.
 */
ll *get_children(ll *the_head, const binary_tree_t *the_parent)
{
	if (the_parent->left)
		the_head = append(the_head, the_parent->left);
	if (the_parent->right)
		the_head = append(the_head, the_parent->right);
	return (the_head);
}

/**
 * append 
 * @the_head: pointer
 * @_binary_node: number
 * Return: pointer to the_head, or NULL on failure
 */
ll *append(ll *the_head, const binary_tree_t *_binary_node)
{
	ll *new = NULL, *last = NULL;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->_node = _binary_node;
		new->next = NULL;
		if (!the_head)
			the_head = new;
		else
		{
			last = the_head;
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	return (the_head);
}

/**
 * free_list - frees all the nodes in a linked list
 * @the_head: pointer to the the_head of list_t linked list
 */
void free_list(ll *the_head)
{
	ll *ptr = NULL;

	while (the_head)
	{
		ptr = the_head->next;
		free(the_head);
		the_head = ptr;
	}
}
