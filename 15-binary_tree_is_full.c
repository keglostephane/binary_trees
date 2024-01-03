#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: a pointer to the root node of the binary tree to check
 *
 * Return: 1 if tree is full else 0
 *
 *
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int lt, rt;

	if (!tree)
		return (0);

	if ((!tree->left && tree->right) || (tree->left && !tree->right))
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
	{
		lt = 1 && binary_tree_is_full(tree->left);
		rt = 1 && binary_tree_is_full(tree->right);
	}

	binary_tree_is_full(tree->left);
	binary_tree_is_full(tree->right);

	return (lt && rt);
}
