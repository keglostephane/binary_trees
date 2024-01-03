#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_postorder - a function that goes to the BT using
 * postorder traversal
 *
 * @tree: ptr to the node to traverse
 * @func: ptr to the function that should be called for each node
 *
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
