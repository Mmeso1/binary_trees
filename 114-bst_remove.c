#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: A pointer to the node containing an int equal to `value`
 *         NULL if tree is NULL
 *         NULL if no match is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)(tree));
	else if (tree->n < value)
		return (bst_search(tree->right, value));
	else if (tree->n > value)
		return (bst_search(tree->left, value));
	return (NULL);
}

/**
 * left_most - finds the smallest node from a Binary Search Tree
 * @node: a pointer to the root node of the tree
 * Return: a pointer to the left_most node
 */

bst_t *left_most(bst_t *node)
{
	bst_t *leftmost = node;

	while (leftmost->left)
		leftmost = leftmost->left;
	return (leftmost);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree after removal
 *         NULL on failure
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *repl;

	if (!root)
		return (NULL);
	node = bst_search(root, value);
	if (node->right)
	{
		repl = left_most(node->right);
		node->n = repl->n;
	}
	else
	{
		repl = node->left;
		if (node->parent)
			node->parent->right = repl;
		else
			root = repl;
		repl->parent = node->parent;
	}
	return (root);
}
