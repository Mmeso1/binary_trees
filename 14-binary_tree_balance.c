#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = tree->left ? 1 + binary_tree_height(tree->left) : 0; 
	r_height = tree->right ? 1 + binary_tree_height(tree->right) : 0; 

	return (l_height - r_height);
}

#include "binary_trees.h"

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
