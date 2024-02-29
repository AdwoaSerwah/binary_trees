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

		visit_node(left_ptr, func);
		visit_node(right_ptr, func);
		func(node->n);
	}
}

/**
 * binary_tree_postorder - Traverses a binary tree using postorder traversal
 * @tree: Pointer to root node
 * @func: Pointer to a function
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL || func != NULL)
		visit_node(tree, func);
}
