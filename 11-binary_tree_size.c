#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the size
 *
 * Return: the size of a tree from a given node.
 *
 * If tree is NULL return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t ltree, rtree;

	if (!tree)
		return (0);

	ltree = binary_tree_size(tree->left);
	rtree = binary_tree_size(tree->right);

	return (ltree + rtree + 1);
}
