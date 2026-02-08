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

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);

    cout << root->key << " -> ";

    inorder(root->right);
  }
}

bool ans = true;

int depth(struct node *root)
{
    if(root==NULL)
        return 0;
    
    int ld = depth(root->left);
    int rd = depth(root->right);
    
    if(abs(ld-rd)>1)
        ans = false;
    
    return 1 + max(ld, rd);
}
    
bool isBalanced(struct node* root) {
    ans= true;
    
    depth(root);
    
    return ans;
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

  cout << "\nInorder traversal: ";
  inorder(root);
  	
  cout << "\nisBalanced: " << isBalanced(root);
  
}
