#include "binary_trees.h"


/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (!tree)
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);
	return ((left_h > right_h ? left_h : right_h) + 1);
}


/**
 * is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Pointer to the minimum value a node can have
 * @max: Pointer to the maximum value a node can have
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	if (!tree)
		return (1);

	if ((min && tree->n <= min->n) || (max && tree->n >= max->n))
		return (0);

	return (is_bst(tree->left, min, tree) && is_bst(tree->right, tree, max));
}


/**
 * binary_tree_is_avl_helper - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree)
{
	int left_h, right_h, balance_factor;

	if (!tree)
		return (1);

	left_h = height(tree->left);
	right_h = height(tree->right);
	balance_factor = left_h - right_h;

	if (balance_factor < -1 || balance_factor > 1)
		return (0);

	return (binary_tree_is_avl_helper(tree->left) &&
			binary_tree_is_avl_helper(tree->right));
}


/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst(tree, NULL, NULL) && binary_tree_is_avl_helper(tree));
}
