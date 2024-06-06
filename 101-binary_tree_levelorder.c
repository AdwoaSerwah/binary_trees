#include "binary_trees.h"

/**
 * visit_node - Visits node
 * @node: Node to visit
 * @func: Function pointer
 */
void visit_node(const binary_tree_t *node, void (*func)(int))
{
	if (node != NULL && func != NULL)
	{
		binary_tree_t *left_ptr = node->left;
		binary_tree_t *right_ptr = node->right;

		if (left_ptr != NULL)
			func(left_ptr->n);
		if (right_ptr != NULL)
			func(right_ptr->n);

		visit_node(left_ptr, func);
		visit_node(right_ptr, func);
	}
}

/**
 * binary_tree_levelorder - Traverses a binary tree using levelorder traversal
 * @tree: Pointer to root node
 * @func: Pointer to a function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL)
		func(tree->n);
	if (tree != NULL && func != NULL)
		visit_node(tree, func);
}
