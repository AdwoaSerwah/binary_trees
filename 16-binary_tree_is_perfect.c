#include "binary_trees.h"

/**
 * visit_node - Visits node
 * @node: Node to visit
 * @is_perfect: Checker
 * @h_c: Current height
 * @h_i: Pointer to initial_height
 *
 * Return: is_perfect
 */
int visit_node(const binary_tree_t *node, int is_perfect, int h_c, int *h_i)
{
	if (node != NULL)
	{
		binary_tree_t *lp = node->left;
		binary_tree_t *rp = node->right;

		if ((lp == NULL && rp != NULL) || (rp == NULL && lp != NULL))
			is_perfect = 0;
		else
		{
			if (lp == NULL && rp == NULL)
			{
				if (*h_i == 0 && h_c > *h_i)
					*h_i = h_c;

				if (*h_i != h_c)
				{
					is_perfect = 0;
					return (is_perfect);
				}
			}
			if (lp != NULL && rp != NULL)
				h_c++;
			is_perfect = visit_node(lp, is_perfect, h_c, h_i);
			is_perfect = visit_node(rp, is_perfect, h_c, h_i);
		}
	}
	return (is_perfect);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to root node
 *
 * Return: is_perfect or 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int is_perfect = 1, current_height = 0, initial_height = 0;

	if (tree == NULL)
		return (0);
	return (visit_node(tree, is_perfect, current_height, &initial_height));
}
