// Binary Search Tree operations in C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node
{
    int key;
    node *left, *right;
 
    node(int data)
    {
        this->key = data;
        this->left = this->right = nullptr;
    }
};


bool isMirror(struct node* root1, struct node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
 
    if (root1 && root2 && root1->key == root2->key)
    {
	    return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
    
    return false;
}
bool isSymmetric(node* root) {
	
	return isMirror(root, root);
}
      
int main() 
{
  struct node *root = NULL;
   
  root = new node(1);
  root->left = new node(2);
  root->right = new node(2);
  root->left->left = new node(3);
  root->left->right = new node(4);
  root->right->left = new node(4);
  root->right->right = new node(3);
  
  cout << "\nisValidBST: " << isSymmetric(root);
  
}
