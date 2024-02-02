#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* Create a queue for level-order traversal */
    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * binary_tree_height(tree) + 1);
    size_t front = 0, rear = 0;
    int is_leaf = 0;

    if (queue == NULL)
        return (0);

    /* Enqueue the root */
    queue[rear] = (binary_tree_t *)tree;
    rear++;

    while (front < rear)
    {
        binary_tree_t *current = queue[front];
        front++;

        /* Check if this node is a leaf or a non-full node */
        if ((current->left && !current->right) || (is_leaf && (current->left || current->right)))
        {
            free(queue);
            return (0);
        }

        /* Enqueue left child */
        if (current->left)
        {
            queue[rear] = current->left;
            rear++;
        }
        else
        {
            is_leaf = 1;
        }

        /* Enqueue right child */
        if (current->right)
        {
            queue[rear] = current->right;
            rear++;
        }
        else
        {
            is_leaf = 1;
        }
    }

    free(queue);
    return (1);
}

