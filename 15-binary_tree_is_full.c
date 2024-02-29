#include "binary_trees.h"

/**
 * visit_node - Visits node
 * @node: Node to visit
 * @is_full: Checker
 *
 * Return: is_full
 */
int visit_node(const binary_tree_t *node, int is_full)
{
	if (node != NULL)
	{
		binary_tree_t *lp = node->left;
		binary_tree_t *rp = node->right;

		if ((lp == NULL && rp != NULL) || (rp == NULL && lp != NULL))
		{
			is_full = 0;
			/* return (is_full); */
		}
		else
		{
			is_full = visit_node(lp, is_full);
			is_full = visit_node(rp, is_full);
		}

	}
	return (is_full);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to root node
 *
 * Return: is_full or 0 if tree is null
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full = 1;

	if (tree == NULL)
		return (0);
	is_full = visit_node(tree, is_full);
	return (is_full);
}
