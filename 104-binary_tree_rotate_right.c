#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate left of a binary tree
 *
 * @tree: pointer to the root node
 *
 * Return: binary tree rotated
 *
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (!tree)
		return (NULL);
	tree->parent = tree->left;
	if (tree->left)
	{
		tree->left = (tree->left)->right;
		(tree->parent)->right = tree;
		(tree->parent)->parent = NULL;
		if (tree->left)
			(tree->left)->parent = tree;
		return (tree->parent);
	}
	return (tree);
}
