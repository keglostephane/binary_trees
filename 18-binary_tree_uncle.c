#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 *
 * @node: a pointer to the node to find the uncle
 *
 * Return: a pointer to the uncle node
 * if node is NULL, return NULL
 * if node has no uncle, return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node && !node->parent)
		return (NULL);
	if (node && node->parent)
	{
		if (!node->parent->parent)
			return (NULL);
		if (node->parent->left == node)
			return (node->parent->parent->left);
		else
			return (node->parent->parent->right);
	}

	return (NULL);
}
