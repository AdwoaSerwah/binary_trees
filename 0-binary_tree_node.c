#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Parent node pointer
 * @value: Value
 *
 * Return: Null or new_node_sk
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node_sk = malloc(sizeof(binary_tree_t));

	if (new_node_sk == NULL)
		return (NULL);

	new_node_sk->n = value;
	new_node_sk->parent = parent;
	new_node_sk->left = NULL;
	new_node_sk->right = NULL;

	return (new_node_sk);
}
