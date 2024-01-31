#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: The ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *temp_first = first, *temp_second = second;
	int depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	while (depth_first > depth_second)
	{
		temp_first = temp_first->parent;
		depth_first--;
	}

	while (depth_second > depth_first)
	{
		temp_second = temp_second->parent;
		depth_second--;
	}

	while (temp_first && temp_second)
	{
		if (temp_first == temp_second)
			return ((binary_tree_t *)temp_first);

		temp_first = temp_first->parent;
		temp_second = temp_second->parent;
	}

	return (NULL);
}


/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth or 0 If tree is NULL
 *
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree && tree->parent)
	{
		depth += (1 + binary_tree_depth(tree->parent));
		return (depth);
	}

	return (0);
}
