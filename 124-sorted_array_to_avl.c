#include "binary_trees.h"
/**
 * aux_sort 
 * @the_parent: pointer
 * @the_array: the_array
 * @the_b: pointer
 * @the_l: pointer
 * Return: tree created
 */
avl_t *aux_sort(avl_t *the_parent, int *the_array, int the_b, int the_l)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (the_b <= the_l)
	{
		mid = (the_b + the_l) / 2;
		aux = binary_tree_node((binary_tree_t *)the_parent, the_array[mid]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, the_array, the_b, mid - 1);
		root->right = aux_sort(root, the_array, mid + 1, the_l);
		return (root);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl 
 * @the_array: array
 * @the_size: array
 * Return: alv tree form sorted the_array
 */
avl_t *sorted_array_to_avl(int *the_array, size_t the_size)
{
	if (the_array == NULL || the_size == 0)
		return (NULL);
	return (aux_sort(NULL, the_array, 0, ((int)(the_size)) - 1));
}
