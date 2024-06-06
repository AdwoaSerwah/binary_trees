#include "binary_trees.h"

/**
 * struct qnode - Queue node
 * @node: Binary tree node
 * @next: Next node in the queue
 */
typedef struct qnode
{
	const binary_tree_t *node;
	struct qnode *next;
} qnode_sk;

/**
 * enqueue - Adds node to queue
 * @queue: Queue
 * @node: Node
 */
void enqueue(qnode_sk **queue, const binary_tree_t *node)
{
	qnode_sk *new_skb = malloc(sizeof(qnode_sk));
	qnode_sk *tmp_skb = *queue;

	if (!new_skb)
		return;
	new_skb->node = node;
	new_skb->next = NULL;

	if (!*queue)
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
 * dequeue - Removes a node from the front of the queue
 * @queue: The queue to remove from
 *
 * Return: The binary tree node removed
 */
const binary_tree_t *dequeue(qnode_sk **queue)
{
	qnode_sk *tmp_skb;
	const binary_tree_t *node;

	if (!*queue)
		return (NULL);
	tmp_skb = *queue;
	node = tmp_skb->node;
	*queue = (*queue)->next;
	free(tmp_skb);
	return (node);
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	qnode_sk *queue = NULL;
	const binary_tree_t *current;

	if (!tree || !func)
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
