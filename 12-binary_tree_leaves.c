#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: number of leaves the binary tree
 *
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t r_leaves, l_leaves;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	l_leaves = binary_tree_leaves(tree->left);
	r_leaves = binary_tree_leaves(tree->right);

	return (l_leaves + r_leaves);
}
