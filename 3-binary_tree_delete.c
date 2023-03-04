#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 *
 * @tree: pointer to the root node of the tree to delete
 *
 * if tree is NULL, do nothing
 *
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *head = tree;

	if (!head)
		return;

	binary_tree_delete(head->left);
	binary_tree_delete(head->right);

	free(head);
}
