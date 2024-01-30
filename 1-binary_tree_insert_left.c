#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a left_node as the
 * left-child of another left_node
 * @parent: pointer to parent left_node
 * @value: value of new left_node
 * Return: pointer to the new left_node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_node;

	if (!parent)
		return (NULL);

	left_node = binary_tree_node(parent, value);
	if (!left_node)
		return (NULL);

	if (parent->left)
	{
		left_node->left = parent->left;
		parent->left->parent = left_node;
	}
	parent->left = left_node;
	
	return (left_node);
}
