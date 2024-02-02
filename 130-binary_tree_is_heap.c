#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* Check if the current node's value is greater than its children's values */
    if ((tree->left && tree->n < tree->left->n) || (tree->right && tree->n < tree->right->n))
        return (0);

    /* Recursively check the left and right subtrees */
    if (!binary_tree_is_heap(tree->left) || !binary_tree_is_heap(tree->right))
        return (0);

    return (1);
}

