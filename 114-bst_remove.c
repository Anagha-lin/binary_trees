#include "binary_trees.h"

/**
 * find_inorder_successor - Finds the in-order successor of a node
 * @node: Pointer to the node
 * Return: Pointer to the in-order successor
 */
bst_t *find_inorder_successor(bst_t *node)
{
    bst_t *current = node->right;

    while (current->left != NULL)
        current = current->left;

    return current;
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the tree
 * @value: Value to remove from the tree
 * Return: Pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else {
        if (root->left == NULL) {
            bst_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        bst_t *temp = find_inorder_successor(root);
        root->n = temp->n;
        root->right = bst_remove(root->right, temp->n);
    }

    return root;
}

