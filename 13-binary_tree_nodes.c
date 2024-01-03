#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes in a binary tree
 * with at least 1 child
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: number of nodes in the binary tree
 *
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t r_nodes, l_nodes;

	if (!tree)
		return (0);
	if (tree->left && tree->right)
		return (1 + binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));

	l_nodes = tree->left ? 1 + binary_tree_nodes(tree->left) : 0;
	r_nodes = tree->right ? 1 + binary_tree_nodes(tree->right) : 0;

	return (l_nodes + r_nodes);
}
