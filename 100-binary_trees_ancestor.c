#include "binary_trees.h"


/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node,
 * or NULL if no common ancestor is found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *temp, *check;

	if (!first || !second)
		return (NULL);

	temp = first;
	while (temp)
	{
		check = second;
		while (check)
		{
			if (temp == check)
				return ((binary_tree_t *)temp);
			check = check->parent;
		}
		temp = temp->parent;
	}

	return (NULL);
}
