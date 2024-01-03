#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_preorder - a function that goes to the BT using
 * pre-order traversal
 *
 * @tree: ptr to the node to traverse
 * @func: ptr to the function that should be called for each node
 *
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
