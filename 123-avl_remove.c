#include "binary_trees.h"


/**
 * find_min - Finds the node with the smallest value in a subtree
 * @node: Pointer to the root of the subtree
 *
 * Return: Pointer to the node with the smallest value
 */
avl_t *find_min(avl_t *node)
{
       	while (node->left)
	       	node = node->left;
	return (node);
}


/**
 * update_balance - Updates and rebalances the AVL tree
 * @node: Pointer to the node to rebalance
 *
 * Return: Pointer to the new root of the subtree
 */
avl_t *update_balance(avl_t *node)
{
	int balance;

	if (!node)
		return (NULL);

	balance = binary_tree_balance(node);

	if (balance > 1)
	{
		if (binary_tree_balance(node->left) < 0)
			node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (balance < -1)
	{
		if (binary_tree_balance(node->right) > 0)
			node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}


/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree
 * @value: The value to remove
 *
 * Return: Pointer to the new root node of the tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}

		temp = find_min(root->right);
		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}

	return (update_balance(root));
}
