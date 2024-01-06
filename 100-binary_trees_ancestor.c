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
 * same_level - returns the parent of the node at the same level
 *		with the node having the smallest depth
 *
 * @node1: pointer to first node
 * @node2: pointer to second node
 *
 * Return: a pointer to the parent of the node at the same level
 *	   with the node having the smallest depth
 */
binary_tree_t *same_level(const binary_tree_t *node1,
			  const binary_tree_t *node2)
{
	size_t dnode1, dnode2, dnode;
	binary_tree_t *node;

	dnode1 = binary_tree_depth(node1);
	dnode2 = binary_tree_depth(node2);
	node = (dnode1 > dnode2) ? (binary_tree_t *)node1 :
		(binary_tree_t *)node2;
	dnode = binary_tree_depth(node);

	if (node == node1)
		while (dnode > dnode2)
		{
			node = node->parent;
			dnode = binary_tree_depth(node);
		}
	if (node == node2)
		while (dnode > dnode1)
		{
			node = node->parent;
			dnode = binary_tree_depth(node);
		}

	return (node);
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
	binary_tree_t *node;

	if (!first || !second)
		return (NULL);

	dfirst = binary_tree_depth(first);
	dsecond = binary_tree_depth(second);

	if (!dfirst || !dsecond)
		return (NULL);

	if (dfirst == dsecond)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		if (first->parent == second->parent)
			return (first->parent);
		if (first->parent != second->parent)
			return (first->parent->parent);
	}
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (second == first->parent)
		return ((binary_tree_t *)second);

	node = same_level(first, second);
	if (dfirst < dsecond)
		return (binary_trees_ancestor(first, node));
	if (dfirst > dsecond)
		return (binary_trees_ancestor(second, node));

	return (NULL);
}
