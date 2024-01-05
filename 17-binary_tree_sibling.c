#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling - return the sibling of a given node
 *
 * @node: pointer to the node to return the sibling
 *
 * Return: pointer to the node of the sibling
 *
 * if node is NULL or the parent is NULL, return NULL
 * if node has no sibling, return NULL
 *
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node && !node->parent)
		return (NULL);
	if (node && node->parent->left == node)
		return (node->parent->right);
	else if (node && node->parent->right == node)
		return (node->parent->left);

	return (NULL);
}
