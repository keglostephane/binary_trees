#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a node as the left-child of another node
 *
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: a pointer to the created node.
 * NULL on failure of if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!parent || !node)
	{
		free(node);
		return (NULL);
	}

	node->n = value;
	node->parent = parent;
	node->right = node->left = NULL;

	if (!parent->left)
		parent->left = node;
	else
	{
		temp = parent->left;
		parent->left = node;
		node->left = temp;
		temp->parent = node;
	}
	return (node);
}
