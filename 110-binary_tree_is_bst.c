#include "binary_trees.h"
#include <limits.h>

int is_bst_helper(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_helper - helper function to recursively check if a binary tree
 *                 is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * @min: the minimum value that a node's data can have
 * @max: the maximum value that a node's data can have
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, max));
}

