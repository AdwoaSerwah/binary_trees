#include "binary_trees.h"

/**
 * count_nodes - Counts node with at least one child
 * @node: Node to visit
 * @count: Current count
 *
 * Return: count
 */
size_t count_nodes(const binary_tree_t *node, size_t count)
{
	if (node != NULL)
	{
		binary_tree_t *left_ptr = node->left;
		binary_tree_t *right_ptr = node->right;

		if (left_ptr != NULL || right_ptr != NULL)
			count++;
		count = count_nodes(left_ptr, count);
		count = count_nodes(right_ptr, count);
	}
	return (count);
}

/**
 * binary_tree_nodes - Counts the nodes with at least one child
 * @tree: Pointer to root node
 *
 * Return: nodes_count or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes_count = 0;

	if (tree != NULL)
	{
		nodes_count = count_nodes(tree, nodes_count);
	}
	return (nodes_count);
}
