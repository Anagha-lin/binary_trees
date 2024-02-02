#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_down - Helper function to restore the Max Heap property
 * @root: Double pointer to the root node of heap
 */
void heapify_down(heap_t **root)
{
    heap_t *current = *root;
    heap_t *child;

    while (1)
    {
        child = NULL;

        if (current->left && current->left->n > current->n)
            child = current->left;
        if (current->right && current->right->n > current->n &&
            (!child || current->right->n > child->n))
            child = current->right;

        if (!child)
            break;

        if (!child->left && !child->right)
            break;

        if (!child->right || child->left->n >= child->right->n)
        {
            if (child->left->n > current->n)
                swap_values(current, child->left);
            current = child->left;
        }
        else
        {
            if (child->right->n > current->n)
                swap_values(current, child->right);
            current = child->right;
        }
    }
}

/**
 * swap_values - Helper function to swap the values of two nodes
 * @node1: First node
 * @node2: Second node
 */
void swap_values(heap_t *node1, heap_t *node2)
{
    int temp = node1->n;

    node1->n = node2->n;
    node2->n = temp;
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last_node, *current;

    if (!root || !*root)
        return (0);

    value = (*root)->n;
    last_node = find_last_node(*root);
    swap_values(*root, last_node);

    if (last_node->parent)
    {
        if (last_node->parent->right == last_node)
            last_node->parent->right = NULL;
        else
            last_node->parent->left = NULL;
    }

    free(last_node);

    current = *root;
    while (current && (current->left || current->right))
        heapify_down(&current);

    return (value);
}

/**
 * find_last_node - Helper function to find the last node in heap
 * @root: Pointer to the root node of heap
 *
 * Return: Pointer to the last node
 */
heap_t *find_last_node(heap_t *root)
{
    heap_t *last_node = NULL;

    if (!root)
        return (NULL);

    last_node = root;

    while (last_node->left || last_node->right)
    {
        if (last_node->right)
            last_node = last_node->right;
        else
            last_node = last_node->left;
    }

    return (last_node);
}

