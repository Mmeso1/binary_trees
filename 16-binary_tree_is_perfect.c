#include "binary_trees.h"
#include <math.h>

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is perfect, else 0. If tree is NULL return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (!tree)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);

	if (l_height != r_height)
		return (0);

	if (binary_tree_nodes(tree) != (size_t)pow(2, l_height))
		return (0);

	binary_tree_is_perfect(tree->left);
	binary_tree_is_perfect(tree->right);

	return (1);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: size of the tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height, r_height, height;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);

	height = (l_height > r_height) ? l_height : r_height;

	return (height + 1);
}

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of nodes
 * Return: the node count, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left, right, count = 0;

	if (!tree)
		return (0);

	if (tree->left || tree->right)
	{
		count += 1;
	}

	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);
	return (count + left + right);
}
