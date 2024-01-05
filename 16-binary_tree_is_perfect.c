#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the binary tree
 *
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lh, rh;

	if (!tree)
		return (0);

	lh = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rh = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (lh > rh ? lh : rh);
}

/**
 * binary_tree_depth - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: depth of the binary tree
 *
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (0);

	depth = tree->parent ? 1 + binary_tree_depth(tree->parent) : 0;
	return (depth);
}


/**
 * is_perfect - check if a binary tree is perfect
 *
 * @tree: a pointer to the root node of the tree to check
 * @height: height of the binary tree
 *
 * Return: 1 if the tree is perfect, otherwise 0
 * if the tree is NULL, return 0
 */
int is_perfect(const binary_tree_t *tree, unsigned int height)
{
	int lt, rt;
	unsigned int depth;

	if (!tree)
		return (0);

	if ((!tree->left && tree->right) || (tree->left && !tree->right))
		return (0);

	if (!tree->left && !tree->right)
	{
		depth = binary_tree_depth(tree);

		if (depth == height)
			return (1);
		else
			return (0);
	}

	lt = 1 && is_perfect(tree->left, height);
	rt = 1 && is_perfect(tree->right, height);

	return (lt && rt);

}
/**
 * binary_tree_is_perfect - wrapper function that checks if a binary tree
 *			    is perfect
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	unsigned int ht = binary_tree_height(tree);

	return (is_perfect(tree, ht));
}
