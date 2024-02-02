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
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of heap
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *sorted_array;
    size_t i;

    if (!heap || !size)
        return (NULL);

    *size = binary_tree_size(heap);
    sorted_array = malloc(sizeof(int) * (*size));
    if (!sorted_array)
        return (NULL);

    for (i = 0; i < *size; ++i)
    {
        sorted_array[i] = heap->n;
        if (i == *size - 1)
            break;

        swap_values(heap, find_last_node(heap));
        if (heap->parent && !heap->parent->left)
            heap->parent->right = NULL;

        heapify_down(&heap);
    }

    return (sorted_array);
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

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

