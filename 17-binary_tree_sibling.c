#include <stdlib.h>
#include "binary_trees.h"
/**
 * is_left_or_right - a function that check if the given ptr
 * is left or right
 *
 * @node: the node
 * @parent: the parent of given node
 *
 * Return: 1 if left, 2 if right
 */
size_t is_left_or_right(binary_tree_t *node, binary_tree_t *parent)
{
	binary_tree_t *lnode, *rnode;

	lnode = parent->left;
	rnode = parent->right;

	if (node == lnode)
		return (1);
	else if (node == rnode)
		return (2);
	else
		return (0);
}
/**
 * binary_tree_sibling - return the sibling of a given node
 *
 * @node: pointer to the node to return the sibling
 *
 * Return: ptr to the node of the sibling
 *
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	size_t l_or_r;
	binary_tree_t *sibling = malloc(sizeof(binary_tree_t));

	if (!sibling)
		return (NULL);

	if (!node || !node->parent)
		return (NULL);
	l_or_r = is_left_or_right(node, node->parent);
	if (l_or_r == 1)
		sibling = (node->parent)->right;
	else if (l_or_r == 2)
		sibling = ((node->parent)->left);
	else
		sibling = NULL;
	return sibling;

}
