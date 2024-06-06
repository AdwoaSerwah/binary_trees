#include "binary_trees.h"

/**
 * enqueue - Adds node to queue
 * @queue: Queue
 * @node: Node
 */
void enqueue(qnode_sk **queue, const binary_tree_t *node)
{
	qnode_sk *new_skb = malloc(sizeof(qnode_sk));
	qnode_sk *tmp_skb = *queue;

	if (new_skb == NULL)
		return;
	new_skb->node = node;
	new_skb->next = NULL;

	if (*queue == NULL)
	{
		*queue = new_skb;
	}
	else
	{
		while (tmp_skb->next)
			tmp_skb = tmp_skb->next;
		tmp_skb->next = new_skb;
	}
}

/**
 * dequeue - Removes node from queue
 * @queue: Queue
 *
 * Return: Node removed
 */
const binary_tree_t *dequeue(qnode_sk **queue)
{
	qnode_sk *tmp_skb;
	const binary_tree_t *node;

	if (*queue == NULL)
		return (NULL);
	tmp_skb = *queue;
	node = tmp_skb->node;
	*queue = (*queue)->next;
	free(tmp_skb);
	return (node);
}

/**
 * binary_tree_levelorder - Traverses a binary tree
 * @tree: Pointer to root node
 * @func: Function pointer
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	qnode_sk *queue = NULL;
	const binary_tree_t *current;

	if (tree == NULL && func == NULL)
		return;

	enqueue(&queue, tree);

	while ((current = dequeue(&queue)))
	{
		func(current->n);
		if (current->left)
			enqueue(&queue, current->left);
		if (current->right)
			enqueue(&queue, current->right);
	}
}
