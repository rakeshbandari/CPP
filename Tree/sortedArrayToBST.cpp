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

node* sortedArrayToBST(vector<int>& arr, int start, int end) 
{ 
    if (start > end) 
    return NULL; 

    int mid = (start + end)/2; 
    node *root = newNode(arr[mid]); 

    root->left = sortedArrayToBST(arr, start, mid - 1); 

    root->right = sortedArrayToBST(arr, mid + 1, end); 

    return root; 
} 

int main() 
{
  struct node *root = NULL;
 
  vector<int> arr = {-10, -3, 0, 5, 9};
  int len = sizeof(arr)/sizeof(arr[0]);
  
  root = sortedArrayToBST(arr, 0, len - 1);
  
  cout << "\nInorder traversal: ";
  inorder(root);
  	
  
  
}
