#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as left-child of another node
 * @parent: Parent node
 * @value: Value
 *
 * Return: new_node_sk OR NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	if (parent->left == NULL)
	{
		parent->left = binary_tree_node(parent, value);
		return (parent->left);
	}
	else
	{
		binary_tree_t *new_node_sk = malloc(sizeof(binary_tree_t));

		if (new_node_sk == NULL)
			return (NULL);
		new_node_sk->n = value;
		new_node_sk->right = NULL;

		new_node_sk->left = parent->left;
		new_node_sk->parent = parent;
		parent->left->parent = new_node_sk;
		parent->left = new_node_sk;

		return (new_node_sk);
	}
}
