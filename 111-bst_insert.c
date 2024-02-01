#include "binary_trees.h"

/**
 * helper - helps
 * @tree: tree
 * @parent: parent
 * @value: value
 * Return: poiner
 */

bst_t *helper(bst_t **tree, bst_t *parent, int value)
{
	bst_t *node;

	if (!*tree)
	{
		node = binary_tree_node(parent, value);
		return (*tree = node);
	}
	else if ((*tree)->n > value)
		return (helper(&(*tree)->left, *tree, value));
	else if ((*tree)->n < value)
		return (helper(&(*tree)->right, *tree, value));
	return (NULL);
}

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: A pointer to the created node
 *         NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);

	return (helper(tree, NULL, value));
}
