#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST)
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert into the BST
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;
	while (current)
	{
		if (value == current->n)
			return (NULL);
		if (value < current->n)
		{
			if (!current->left)
			{
				current->left = binary_tree_node(current,
						value);
				return (current->left);
			}
			current = current->left;
		}
		else
		{
			if (!current->right)
			{
				current->right = binary_tree_node(current,
						value);
				return (current->right);
			}
			current = current->right;
		}
	}
	return (NULL);
}
