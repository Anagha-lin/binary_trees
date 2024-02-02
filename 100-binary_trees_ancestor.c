#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if none found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    if (first == NULL || second == NULL)
        return NULL;

    if (first == second)
        return (binary_tree_t *)first;

    if (first == second->parent || second == first->parent)
        return (binary_tree_t *)first->parent;

    return binary_trees_ancestor(first->parent, second->parent);
}

