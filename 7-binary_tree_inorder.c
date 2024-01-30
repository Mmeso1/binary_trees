#include "binary_trees.h"

/**
 * binary_tree_inorder - traverses the tree in order
 * @tree: a pointer to the root node of the tree to traverse
 * @func:  pointer to a function to call for each node
 * Return: Nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
