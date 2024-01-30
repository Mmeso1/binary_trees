#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a right_node as the
 * right-child of another node
 * @parent: pointer to parent node
 * @value: value of new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_node;

	if (!parent)
		return (NULL);

	right_node = binary_tree_node(parent, value);
	if (!right_node)
		return (NULL);

	if (parent->right)
	{
		right_node->right = parent->right;
		parent->right->parent = right_node;
	}
	parent->right = right_node;

	return (right_node);
}
