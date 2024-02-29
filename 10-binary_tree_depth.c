#include "binary_trees.h"

/**
 * find_depth - Finds the depth of a node
 * @node: Node to find depth of
 * @current_depth: Current depth
 *
 * Return: current_depth
 */
size_t find_depth(const binary_tree_t *node, size_t current_depth)
{
	if (node != NULL)
	{
		if (node->parent != NULL)
		{
			binary_tree_t *p_node = node->parent;

			current_depth++;
			current_depth = find_depth(p_node, current_depth);
		}
	}
	return (current_depth);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Node to measure
 *
 * Return: node_depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t node_depth = 0;

	if (tree != NULL)
		node_depth = find_depth(tree, node_depth);

	return (node_depth);
}
