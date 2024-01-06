#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: depth of the binary tree
 *
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (0);

	depth = tree->parent ? 1 + binary_tree_depth(tree->parent) : 0;
	return (depth);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node of two given nodes
 * if no common ancestor was found, return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t dfirst, dsecond;

	if (!first || !second)
		return (NULL);

	dfirst = binary_tree_depth(first);
	dsecond = binary_tree_depth(second);

	if (first == second)
		return ((binary_tree_t *)first);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (second == first->parent)
		return ((binary_tree_t *)second);
	if (first->parent == second->parent)
		return (first->parent);

	if (dfirst == dsecond)
		return (binary_trees_ancestor(first->parent, second->parent));
	else if (dfirst < dsecond)
		return (binary_trees_ancestor(first, second->parent));
	else
		return (binary_trees_ancestor(first->parent, second));

	return (NULL);
}
