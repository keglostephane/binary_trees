#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 *
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: a pointer to the created node.
 * NULL on failure or if parent is NULL
 *
 * if parent already has a left-child, the new node must take its place,
 * and the old left-child must be set as the left-child of the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *temp, *node = malloc(sizeof(binary_tree_t));

	if (!node || !parent)
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
