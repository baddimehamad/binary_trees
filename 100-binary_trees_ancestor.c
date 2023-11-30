#include "binary_trees.h"

/**
 * binary_trees_ancestor
 * @_one: pointer
 * @_two: pointer
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *_one,
		const binary_tree_t *_two)
{
	binary_tree_t *the_mom, *the_pop;

	if (!_one || !_two)
		return (NULL);
	if (_one == _two)
		return ((binary_tree_t *)_one);

	the_mom = _one->parent, the_pop = _two->parent;
	if (_one == the_pop || !the_mom || (!the_mom->parent && the_pop))
		return (binary_trees_ancestor(_one, the_pop));
	else if (the_mom == _two || !the_pop || (!the_pop->parent && the_mom))
		return (binary_trees_ancestor(the_mom, _two));
	return (binary_trees_ancestor(the_mom, the_pop));
}
