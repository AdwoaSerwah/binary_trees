#include "binary_trees.h"

/**
 * count_leaves - Visits node
 * @node: Node to visit
 * @count: Current count of tree
 *
 * Return: count
 */
size_t count_leaves(const binary_tree_t *node, size_t count)
{
	if (node != NULL)
	{
		binary_tree_t *left_ptr = node->left;
		binary_tree_t *right_ptr = node->right;

		if (left_ptr == NULL && right_ptr == NULL)
			count++;
		count = count_leaves(left_ptr, count);
		count = count_leaves(right_ptr, count);
	}
	return (count);
}

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to root node
 *
 * Return: leaves_count or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves_count = 0;

	if (tree != NULL)
	{
		leaves_count = count_leaves(tree, leaves_count);
	}
	return (leaves_count);
}
