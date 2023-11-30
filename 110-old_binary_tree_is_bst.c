#include "binary_trees.h"
#include "limits.h"
int is_bst_helper(const binary_tree_t *_tree, int *large);

#define VERBOSE 0

/**
 * binary_tree_is_bst
 * @_tree: pointer
 *
 * Return: if the _tree NUll or the function return zero or 1.
 */
int binary_tree_is_bst(const binary_tree_t *_tree)
{
	int _the_track = INT_MIN;

	if (_tree == NULL)
		return (0);
	return (is_bst_helper(_tree, &_the_track));
}


/**
 * is_left 
 * @_node: pointer
 * Return: if the _tree NUll or the function return zero or 1.
 */
int is_left(const binary_tree_t *_node)
{
	if (_node && _node->parent)
		return (_node->parent->left == _node);
	return (0);
}
/**
 * is_right 
 * @_node: pointer
 * Return: if the _tree NUll or the function return zero or 1.
 */
int is_right(const binary_tree_t *_node)
{
	if (_node && _node->parent)
		return (_node->parent->right == _node);
	return (0);
}

#if !VERBOSE
/**
 * is_bst_helper 
 * @_tree: pointer
 * @large: number
 *
 * Return: if the _tree NUll or the function return zero or 1.
 */
int is_bst_helper(const binary_tree_t *_tree, int *large)
{
	int ret = 1;

	if (_tree != NULL)
	{
		ret *= is_bst_helper(_tree->left, large);
		if (_tree->n < *large)
			return (0);
		*large = _tree->n;
		if (is_left(_tree) && !(_tree->n < _tree->parent->n))
			return (0);
		if (is_right(_tree) && !(_tree->n > _tree->parent->n))
			return (0);
		ret *= is_bst_helper(_tree->right, large);
	}
	return (ret);
}
#else
/**
 * is_bst_helper 
 * @_tree: pointer 
 * @large: number
 *
 * Return: if the _tree NUll or the function return zero or 1.
 */
int is_bst_helper(const binary_tree_t *_tree, int *large)
{
	int ret = 1;

	if (_tree)
	{
		printf("Moving to %d\n", _tree->n);
		ret *= is_bst_helper(_tree->left, large);
		printf("done with left _tree for %d: %d\n", _tree->n, ret);
		printf("large = %d\n", *large);
		if (_tree->n < *large)
			return (0);
		*large = _tree->n;
		printf("large = %d\n", *large);
		if (is_left(_tree))
			printf("%d is %s than %d\n",
				_tree->n,
				(_tree->n < _tree->parent->n) ? "smaller" : "larger",
				_tree->parent->n);
		if (is_left(_tree) && !(_tree->n < _tree->parent->n))
		{
			printf("%d is left child\n", _tree->n);
			return (0);
		}
		if (is_right(_tree))
			printf("%d is %s than %d\n",
				_tree->n,
				(_tree->n < _tree->parent->n) ? "smaller" : "larger",
				_tree->parent->n);
		if (is_right(_tree) && !(_tree->n > _tree->parent->n))
		{
			printf("%d is right child\n", _tree->n);
			return (0);
		}
		ret *= is_bst_helper(_tree->right, large);
		printf("done with right _tree for %d: %d\n", _tree->n, ret);
		if (_tree->parent)
			printf("Moving back to %d\n", _tree->parent->n);
	}
	return (ret);
}
#endif /* VERBOSE */
