#include "binary_trees.h"

/**
 * visit_node - Visits node
 * @node: Node to visit
 * @current: Current height
 * @max: Highest height
 *
 * Return: max
 */
int visit_node(const binary_tree_t *node, int current, int max)
{
	if (node != NULL)
	{
		current++;
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

			/* current++; */
			max = visit_node(left_ptr, current, max);
			max = visit_node(right_ptr, current, max);
		}
		/* return (max); */
	}
	return (max);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to root node
 *
 * Return: tree_balance or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int tree_balance = 0;

	if (tree != NULL)
	{
		const binary_tree_t *left_tree = tree->left;
		const binary_tree_t *right_tree = tree->right;
		int current_height = 0, max_height = 0;
		int l_height, r_height;

		l_height = visit_node(left_tree, current_height, max_height);
		r_height = visit_node(right_tree, current_height, max_height);
		tree_balance = l_height - r_height;
	}

	return (tree_balance);
}
