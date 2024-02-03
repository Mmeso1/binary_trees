#include "binary_trees.h"

/**
 * is_avl - helps
 * @tree: tree to traverse
 * @min: min
 * @max: max
 * Return: val
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
	signed int lheight, rheight;

	if (!tree)
		return (1);
	if (tree->n > max || tree->n < min)
		return (0);

	lheight = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rheight = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(lheight - rheight) > 1)
		return (0);

	return (is_avl(tree->left, min, tree->n - 1) &&
			is_avl(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - finds if a binary tree is an avl
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is avl
 *         0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftheight = 0, rightheight = 0;

	if (!tree || (!tree->right && !tree->left))
		return (0);

	leftheight += (1 + binary_tree_height(tree->left));
	rightheight += (1 + binary_tree_height(tree->right));

	return (leftheight >= rightheight ? leftheight : rightheight);
}
