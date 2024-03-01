#include "binary_trees.h"

/**
 * find_depth - Finds the depth of a node
 * @node: Node
 *
 * Return: count
 */
int find_depth(const binary_tree_t *node)
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
	int first_depth, second_depth;

	if (first == NULL || second == NULL)
		return (NULL);
	first_depth = find_depth(first);
	second_depth = find_depth(second);
	while (first_depth > second_depth)
	{
		first = first->parent;
		first_depth--;
	}
	while (second_depth > first_depth)
	{
		second = second->parent;
		second_depth--;
	}
	while (first != second)
	{
		if (first == NULL || second == NULL)
			return (NULL);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
