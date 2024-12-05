#include "binary_trees.h"


/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue, *node;
	size_t front = 0, back = 0, queue_size = 1024;
	int found_null = 0;

	if (!tree)
		return (0);

	queue = malloc(queue_size * sizeof(*queue));
	if (!queue)
		return (0);

	queue[back++] = tree;
	while (front < back)
	{
		node = queue[front++];
		if (node)
		{
			if (found_null)
			{
				free(queue);
				return (0);
			}
			if (back >= queue_size)
			{
				queue_size *= 2;
				queue = realloc(queue,
						queue_size * sizeof(*queue));
				if (!queue)
					return (0);
			}
			queue[back++] = node->left;
			queue[back++] = node->right;
		}
		else
			found_null = 1;
	}
	free(queue);
	return (1);
}
