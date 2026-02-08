// Binary Search Tree operations in C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);

    cout << root->key << " -> ";

    inorder(root->right);
  }
}

struct node *insert(struct node *node, int key) 
{
  if (node == NULL) return newNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

int maxDepth(struct node *root) 
{
    if(root == NULL) return 0;
    
    if(root->left == NULL && root->right == NULL) return 1;
    
    int left = maxDepth(root->left) + 1;
    int right = maxDepth(root->right) + 1;
    
    return max(left, right);         
}
      
int main() 
{
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "\nInorder traversal: ";
  inorder(root);
  	
  cout << "\nmaxDepth: " << maxDepth(root);
  
}
