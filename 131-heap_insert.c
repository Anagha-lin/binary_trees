#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;

    if (!root)
        return (NULL);

    new_node = binary_tree_node(*root, value);
    if (!new_node)
        return (NULL);

    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    insert_last_node(*root, new_node);

    heapify(new_node);

    return (new_node);
}

/**
 * insert_last_node - Inserts the new node at the last available position
 * @root: Root of the tree
 * @new_node: New node to insert
 */
void insert_last_node(heap_t *root, heap_t *new_node)
{
    int node_count = binary_tree_size(root) + 1;
    int mask = 1 << (node_count - 2);

    while (mask > 0)
    {
        if (node_count & mask)
        {
            if (!(mask & 1))
                root = root->left;
            else
                root = root->right;
        }
        mask >>= 1;
    }

    if (!(node_count & 1))
        root->left = new_node;
    else
        root->right = new_node;

    new_node->parent = root;
}

/**
 * heapify - Restores the heap property after insertion
 * @node: Node to start the heapification process
 */
void heapify(heap_t *node)
{
    while (node && node->parent)
    {
        if (node->n > node->parent->n)
        {
            swap_values(node, node->parent);
            node = node->parent;
        }
        else
        {
            break;
        }
    }
}

/**
 * swap_values - Swaps the values of two nodes
 * @node1: First node
 * @node2: Second node
 */
void swap_values(heap_t *node1, heap_t *node2)
{
    int temp;

    temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}

/**
 * binary_tree_size - Computes the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree
 */
int binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

