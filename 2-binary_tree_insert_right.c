#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as right-child of another node
 * @parent: Parent node
 * @value: Value
 *
 * Return: new_node_sk OR NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	if (parent->right == NULL)
	{
		parent->right = binary_tree_node(parent, value);
		return (parent->right);
	}
	else
	{
		binary_tree_t *new_node_sk = malloc(sizeof(binary_tree_t));

		if (new_node_sk == NULL)
			return (NULL);
		new_node_sk->n = value;
		new_node_sk->left = NULL;

		new_node_sk->right = parent->right;
		new_node_sk->parent = parent;
		parent->right->parent = new_node_sk;
		parent->right = new_node_sk;

		return (new_node_sk);
	}
}

