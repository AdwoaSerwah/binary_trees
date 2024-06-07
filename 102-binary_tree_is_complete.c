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
 * binary_tree_height_2 - Measures the height of a binary tree
 * @tree: Pointer to root node
 *
 * Return: tree_height or 0 if tree is NULL
 */
int binary_tree_height_2(const binary_tree_t *tree)
{
	int tree_height = 0;

	if (tree != NULL)
	{
		int current_height = 0, max_height = 0;

		tree_height = visit_node(tree, current_height, max_height);
	}

	return (tree_height);
}

/**
 * is_complete - Checks if a tree is complete
 * @tree: Tree
 * @complete: Integer
 *
 * Return: 0 on failure, 1 on success
 */
int is_complete(const binary_tree_t *tree, int complete)
{
	if (tree != NULL)
	{
		binary_tree_t *lp = tree->left;
		binary_tree_t *rp = tree->right;
		int height = binary_tree_height_2(tree);

		if (height != 0)
		{
			if (height - 1 != 0)
			{
				if (lp == NULL && rp == NULL)
					complete = 0;
				if ((lp == NULL && rp != NULL) ||
						(lp != NULL && rp == NULL))
					complete = 0;
			}
			else
			{
				if (lp == NULL && rp != NULL)
					complete = 0;
				else if (tree->parent != NULL)
				{
				binary_tree_t *tp = tree->parent;

				if (tp->left != tree &&
						(tp->right->left != NULL ||
						 tp->right->right != NULL) &&
						(tp->left->left == NULL ||
						 tp->left->right == NULL))
					complete = 0;
				}
			}
		}
		complete = is_complete(lp, complete);
		complete = is_complete(rp, complete);

	}
		return (complete);
}

/**
 * binary_tree_is_complete - Checks if a tree is complete
 * @tree: Tree to check
 *
 * Return: 0 on error, 1 on success
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int complete = 1;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	complete = is_complete(tree, complete);
	return (complete);
}
