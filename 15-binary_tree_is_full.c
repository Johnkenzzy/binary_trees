#include "binary_trees.h"


/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise, or 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int has_left_child, has_right_child;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
	{
		has_left_child = binary_tree_is_full(tree->left);
		has_right_child = binary_tree_is_full(tree->right);
		return (has_left_child && has_right_child);
	}

	return (0);
}
