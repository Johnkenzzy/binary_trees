#include "binary_trees.h"


/**
 * update_balance_and_rebalance - Updates balance factor & performs rotations
 * @node: Pointer to the node to check for balancing
 *
 * Return: Pointer to the new root after balancing
 */
avl_t *update_balance_and_rebalance(avl_t *node)
{
	int balance_factor;

	if (!node)
		return (NULL);

	balance_factor = binary_tree_balance(node);

	if (balance_factor > 1)
	{
		if (binary_tree_balance(node->left) < 0)
			node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}

	if (balance_factor < -1)
	{
		if (binary_tree_balance(node->right) > 0)
			node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}


/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to insert
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->left = new_node;
		}
		else
			new_node = avl_insert(&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->right = new_node;
		}
		else
			new_node = avl_insert(&(*tree)->right, value);
	}
	else
		return (NULL);
	*tree = update_balance_and_rebalance(*tree);
	return (new_node);
}
