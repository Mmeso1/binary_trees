#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of nodes
 * Return: the node count, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	if (tree->left || tree->right)
	{
		left = binary_tree_nodes(tree->left);
		right = binary_tree_nodes(tree->right);
		return (1 + left + right);
	}
	return (0);
}
