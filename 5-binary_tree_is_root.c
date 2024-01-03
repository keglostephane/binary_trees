#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_root - a function that checks if a ginven node is a root
 *
 * @node: ptr to node to check
 *
 * Return: 1 if root, 0 else.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->parent)
		return (1);
	return (0);
}
