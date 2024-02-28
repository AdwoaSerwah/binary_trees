#include "binary_trees.h"

/**
 * free_node - Frees tree node
 * @node: Pointer to node
 */
void free_node(binary_tree_t *node)
{
	if (node != NULL)
	{
		binary_tree_t *left_ptr = node->left;
		binary_tree_t *right_ptr = node->right;

		free(node);
		node = NULL;

		free_node(left_ptr);
		free_node(right_ptr);

	}
	else
		return;
}

/**
 * binary_tree_delete - Deletes a binary tree
 * @tree: Pointer to root node
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		free_node(tree);
	}
}
