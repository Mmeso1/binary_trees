#include <stdio.h>
#include "binary_trees.h"

void process_level(const binary_tree_t *tree, void (*func)(int), int level);

/**
 * binary_tree_levelorder - traverses the tree in level order
 * @tree: a pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = binary_tree_height(tree);
	int level;

	for (level = 0; level <= height; level++)
	{
		process_level(tree, func, level + 1);
	}
}

/**
 * process_level - processes nodes at a given level of the tree
 * @tree: a pointer to the root node of the tree
 * @func: pointer to a function to call for each node
 * @level: the level of the tree to process
 * Return: Nothing
 */
void process_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL)
		return;

	if (level == 1)
	{
		func(tree->n);
	}
	else if (level > 1)
	{
		process_level(tree->left, func, level - 1);
		process_level(tree->right, func, level - 1);
	}
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
