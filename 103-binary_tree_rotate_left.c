#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree && tree->right)
	{
		binary_tree_t *new_root;

		new_root = tree->right;
		new_root->parent = NULL;
		tree->parent = new_root;
		tree->right = new_root->left;
		if (new_root->left)
			tree->right->parent = new_root->left;
		new_root->left = tree;

		return (new_root);
	}
	return (NULL);
}
