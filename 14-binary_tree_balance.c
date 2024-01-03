#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor of a given binary tree
 *
 */
int binary_tree_balance(const binary_tree_t *tree)
{

	if (!tree)
		return (0);

	if (!tree->left)
		return (0 - binary_tree_height(tree));
	if (!tree->right)
		return (binary_tree_height(tree));

	return (binary_tree_height(tree->left) -
		binary_tree_height(tree->right));
}
