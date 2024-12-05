#include "binary_trees.h"


/**
 * binary_tree_levelorder - Goes through a binary tree by level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue, *node;
	size_t front = 0, back = 0, queue_size = 1024;

	if (!tree || !func)
		return;
	queue = malloc(queue_size * sizeof(*queue));
	if (!queue)
		return;

	queue[back++] = tree;
	while (front < back)
	{
		node = queue[front++];
		func(node->n);
		if (node->left)
		{
			if (back >= queue_size)
			{
				queue_size *= 2;
				queue = realloc(queue,
						queue_size * sizeof(*queue));
				if (!queue)
					return;
			}
			queue[back++] = node->left;
		}
		if (node->right)
		{
			if (back >= queue_size)
			{
				queue_size *= 2;
				queue = realloc(queue,
						queue_size * sizeof(*queue));
				if (!queue)
					return;
			}
			queue[back++] = node->right;
		}
	}
	free(queue);
}
