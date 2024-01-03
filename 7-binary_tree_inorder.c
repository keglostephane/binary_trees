#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_inorder - a function that goes to the BT using
 * inorder traversal
 *
 * @tree: ptr to the node to traverse
 * @func: ptr to the function that should be called for each node
 *
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
