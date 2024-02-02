#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
    avl_t *root = NULL;
    size_t i;

    for (i = 0; i < size; i++)
    {
        if (avl_insert(&root, array[i]) == NULL)
        {
            /* If insertion fails, return NULL */
            return (NULL);
        }
    }

    return (root);
}

