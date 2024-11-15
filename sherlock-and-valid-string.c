/* https://www.hackerrank.com/challenges/sherlock-and-valid-string */
/* Difficulty Easy */
/* TODO: REFACTOR */

#include <stdio.h>
#include <stdlib.h>

struct BSTNode {
  int key;
  int count;
  struct BSTNode *right;
  struct BSTNode *left;
};

struct BSTNode *add_to_bst(struct BSTNode *root, int key) {
  if (root == NULL) {
    struct BSTNode *new_node = malloc(sizeof(struct BSTNode));
    if (new_node == NULL)
      return NULL;
    new_node->key = key;
    new_node->count = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
  }

  if (root->key > key) {
    root->left = add_to_bst(root->left, key);
  } else if (root->key < key) {
    root->right = add_to_bst(root->right, key);
  } else {
    root->count = root->count + 1;
  }

  return root;
}

void count_nodes_bst(struct BSTNode *root, int *count) {
  if (root == NULL) {
    return;
  }
  *count = *count + 1;
  count_nodes_bst(root->left, count);
  count_nodes_bst(root->right, count);
}

char *isValid(char *s) {

  char *YES = "YES\0";
  char *NO = "NO\0";

  int alphabet_frq[26] = {0};
  int c = 0;
  struct BSTNode *root = NULL;

  while (s[c] != '\0') {
    char read_char = s[c];
    alphabet_frq[read_char - 97] += 1;
    c += 1;
  }

  for (int i = 0; i < 26; i += 1) {
    if (alphabet_frq[i]) {
      root = add_to_bst(root, alphabet_frq[i]);
    }
  }

  int *count_nodes_prt = malloc(sizeof(int));
  *count_nodes_prt = 0;
  count_nodes_bst(root, count_nodes_prt);

  if (*count_nodes_prt == 1)
    return YES;
  else if (*count_nodes_prt > 2)
    return NO;

  if (root->left != NULL) {
    if ((root->key == 1 && root->count == 1) ||
        (root->left->key == 1 && root->left->count == 1))
      return YES;
    if (root->count > root->left->count) {
      if (root->left->key - 1 == root->key)
        return YES;
      return NO;
    }
  } else {

    if ((root->key == 1 && root->count == 1) ||
        (root->right->key == 1 && root->right->count == 1))
      return YES;

    if (root->count > root->right->count) {
      if (root->right->key - 1 == root->key)
        return YES;
      return NO;
    }
  }

  return NO;
}