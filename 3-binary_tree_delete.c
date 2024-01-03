#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - delete an entire binary tree
 *
 * @tree: pointer to the root node of the tree to delete
 *
 * if tree is NULL, do nothing
 *
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *root = tree;

	if (!root)
		return;

	binary_tree_delete(root->left);
	binary_tree_delete(root->right);

	free(root);
}
