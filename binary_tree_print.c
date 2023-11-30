#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char array_b[6];
	int the_width, the_left, right, is_left, val_i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	the_width = sprintf(array_b, "(%03d)", tree->n);
	the_left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + the_left + the_width, depth + 1, s);
	for (val_i = 0; val_i < the_width; val_i++)
		s[depth][offset + the_left + val_i] = array_b[val_i];
	if (depth && is_left)
	{
		for (val_i = 0; val_i < the_width + right; val_i++)
			s[depth - 1][offset + the_left + the_width / 2 + val_i] = '-';
		s[depth - 1][offset + the_left + the_width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (val_i = 0; val_i < the_left + the_width; val_i++)
			s[depth - 1][offset - the_width / 2 + val_i] = '-';
		s[depth - 1][offset + the_left + the_width / 2] = '.';
	}
	return (the_left + the_width + right);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, val_i, j;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (val_i = 0; val_i < height + 1; val_i++)
	{
		s[val_i] = malloc(sizeof(**s) * 255);
		if (!s[val_i])
			return;
		memset(s[val_i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (val_i = 0; val_i < height + 1; val_i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[val_i][j] != ' ')
				break;
			s[val_i][j] = '\0';
		}
		printf("%s\n", s[val_i]);
		free(s[val_i]);
	}
	free(s);
}
