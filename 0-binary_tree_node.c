#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - create a binary tree node
 *
 * @parent: pointer to node parent
 * @value: node data
 *
 * Return: a pointer to the new node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);

	node->n = value;

	if (!parent)
	{
		node->parent = NULL;
		parent = node;
	}
	else
		node->parent = parent;

	node->left = node->right = NULL;
	return (node);
}
