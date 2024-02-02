#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST)
 * @tree: Double pointer to the root node of the BST
 * @value: Value to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *current, *parent;

    if (tree == NULL)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = new_node;
        return (new_node);
    }

    current = *tree;
    parent = NULL;

    while (current != NULL)
    {
        parent = current;

        if (value == current->n)
        {
            free(new_node);
            return (NULL); /* Value already exists, ignore */
        }
        else if (value < current->n)
            current = current->left;
        else
            current = current->right;
    }

    if (value < parent->n)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;

    return (new_node);
}

