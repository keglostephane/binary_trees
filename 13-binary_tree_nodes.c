#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in binary tree
 *
 * @tree: a pointer to the root node of the tree to count the number of nodes
 *
 * Return: number of nodes with at least 1 child from a given node
 *
 * If tree is NULL return 0
 *
 * A NULL pointer is not a node
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t lt, rt;

	if (!tree)
		return (0);

	if (tree->left && tree->right)
		return (1 + binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));

	lt = (tree->left) ? 1 + binary_tree_nodes(tree->left) : 0;
	rt = (tree->right) ? 1 + binary_tree_nodes(tree->right) : 0;

	return (lt + rt);
}
