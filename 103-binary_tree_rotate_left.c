#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate left of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: binary tree rotated
 *
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (!tree)
		return (NULL);
	tree->parent = tree->right;
	if (tree->right)
	{
		tree->right = (tree->right)->left;
		(tree->parent)->left = tree;
		(tree->parent)->parent = NULL;
		if (tree->right)
			(tree->right)->parent = tree;
		return (tree->parent);
	}
	return (tree);
}
