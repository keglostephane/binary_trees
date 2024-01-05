#include <stdlib.h>
#include "binary_trees.h"
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
 * print_level - a function that print level
 * @tree: ptr to tree
 * @level: level to print
 * @func: ptr to the function
 *
 */
void print_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - a function that goes to the BT using
 * levelorder traversal
 *
 * @tree: ptr to the node to traverse
 * @func: ptr to the function that should be called for each node
 *
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i;
	size_t height = binary_tree_height(tree);

	if (!tree || !func)
		return;
	for (i = 1; i <= height + 1; i++)
		print_level(tree, i, func);

}
