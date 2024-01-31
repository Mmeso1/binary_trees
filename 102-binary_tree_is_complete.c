#include <stdio.h>
#include "binary_trees.h"

int count_nodes(const binary_tree_t *tree);
int is_complete_helper(const binary_tree_t *tree, int index, int total_nodes);

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int total_nodes;

	if (tree == NULL)
		return (0);

	total_nodes = count_nodes(tree);

	return (is_complete_helper(tree, 0, total_nodes));
}

/**
 * count_nodes - counts the total number of nodes in a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: total number of nodes
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete_helper - helper function to recursively check completeness
 * @tree: a pointer to the root node of the tree
 * @index: index of the current node
 * @total_nodes: total number of nodes in the tree
 * Return: 1 if complete, 0 otherwise
 */
int is_complete_helper(const binary_tree_t *tree, int index, int total_nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= total_nodes || (tree == NULL && index < total_nodes))
		return (0);

	return (is_complete_helper(tree->left, 2 * index + 1, total_nodes) &&
			is_complete_helper(tree->right, 2 * index + 2, total_nodes));
}

