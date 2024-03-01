#include "binary_trees.h"

/**
 * find_depth1 - Finds the depth of a node
 * @node: Node
 *
 * Return: depth
 */
int find_depth1(const binary_tree_t *node)
{
	int count = 0;
	const binary_tree_t *ptr = node;

	while (ptr->parent != NULL)
	{
		count++;
		ptr = ptr->parent;
	}
	return (count);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: First node
 * @second: Second node
 *
 * Return: NULL or pointer to ancestor
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	int first_depth = 0, second_depth = 0;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first->parent == NULL)
		return ((binary_tree_t *) first);
	if (second->parent == NULL)
		return ((binary_tree_t *) second);
	first_depth = find_depth1(first), second_depth = find_depth1(second);
	if (first_depth != second_depth)
	{
		if (first_depth > second_depth)
		{
			while (first_depth != second_depth)
			{
				if (first->parent == second)
					return (first->parent);
				first_depth--;
				first = first->parent;
			}
		}
		else
		{
			while (second_depth != first_depth)
			{
				if (second->parent == first)
					return (second->parent);
				second_depth--;
				second = second->parent;
			}
		}
	}
	while (first_depth > 0)
	{
		if (first->parent == second->parent)
			return (first->parent);
		first = first->parent;
		second = second->parent;
	}
	return (NULL);
}
