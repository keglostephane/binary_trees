#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert a node as the right-child of another node
 *
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: a pointer to the created node or NULL on failure or
 * if parent is NUL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *temp, *node;

	node = malloc(sizeof(binary_tree_t));

	if (!parent || !node)
	{
		free(node);
		return (NULL);
	}

	node->n = value;
	node->parent = parent;
	node->right = node->left = NULL;

	if (!parent->right)
		parent->right = node;
	else
	{
		temp = parent->right;
		parent->right = node;
		node->right = temp;
		temp->parent = node;
	}
	return (node);
}
