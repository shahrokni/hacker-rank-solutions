#include <stdlib.h>

struct BSTNode {
  int key;
  struct BSTNode *right;
  struct BSTNode *left;
};

struct BSTNode *add_to_bst(struct BSTNode *root, int key) {
  if (root == NULL) {
    struct BSTNode *new_node = malloc(sizeof(struct BSTNode));
    if (new_node == NULL)
      return NULL;
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  }

  if (root->key > key) {
    root->left = add_to_bst(root->left, key);
  } else if (root->key < key) {
    root->right = add_to_bst(root->right, key);
  }

  return root;
}