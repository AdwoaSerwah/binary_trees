#include "binary_trees.h"

/**
 * count_node - Visits node
 * @node: Node to visit
 * @size: Current size of tree
 *
 * Return: size
 */
size_t count_node(const binary_tree_t *node, size_t size)
{
	if (node != NULL)
	{
		binary_tree_t *left_ptr = node->left;
		binary_tree_t *right_ptr = node->right;

		size++;
		size = count_node(left_ptr, size);
		size = count_node(right_ptr, size);
	}
	return (size);
}

/**
 * binary_tree_size - Measures size of a binary tree
 * @tree: Pointer to root node
 *
 * Return: tree_size or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t tree_size = 0;

	if (tree != NULL)
	{
		tree_size = count_node(tree, tree_size);
	}
	return (tree_size);
}
