#include "binary_trees.h"

/**
 * visit_node - Visits node
 * @node: Node to visit
 * @current: Current height
 * @max: Highest height
 *
 * Return: max
 */
size_t visit_node(const binary_tree_t *node, size_t current, size_t max)
{
	if (node != NULL)
	{
		if (node->left == NULL && node->right == NULL)
		{
			if (current > max)
				max = current;
			/* return (max); */
		}
		else
		{
			binary_tree_t *left_ptr = node->left;
			binary_tree_t *right_ptr = node->right;

			current++;
			max = visit_node(left_ptr, current, max);
			max = visit_node(right_ptr, current, max);
		}
		/* return (max); */
	}
	return (max);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to root node
 *
 * Return: tree_height or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t tree_height = 0;

	if (tree != NULL)
	{
		size_t current_height = 0, max_height = 0;

		tree_height = visit_node(tree, current_height, max_height);
	}

	return (tree_height);
}
