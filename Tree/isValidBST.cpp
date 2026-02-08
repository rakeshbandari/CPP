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

vector<int> v;
bool isValidBST(node* root) {
	
	if (root == NULL) 
		return true;
	
	bool left = isValidBST(root->left);
	
	v.push_back(root->key);
	
	if (v.size() >= 2 && v[v.size() - 1] <= v[v.size() - 2]) 
	{		
    	return false;   	
	}	
	
	bool right = isValidBST(root->right);
	
	return left && right;
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
  	
  cout << "\nisValidBST: " << isValidBST(root);
  
}
