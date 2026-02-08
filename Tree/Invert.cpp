// Binary Search Tree operations in C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
 
    node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

void inOrder(struct node* root){
	if(root == NULL) return;
	
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
	
}


struct node* invertTree(struct node* root) {
    if(root==NULL) {
        return root;
    }
    if(root->left == NULL && root->right == NULL) {
        return root;
    }
    
    if(root->left != NULL && root->right != NULL) {
        struct node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
    }
    else if(root->left == NULL) {
        root->left = root->right;
        root->right = NULL;
        invertTree(root->left);
    }
    else if(root->right==NULL) {
        root->right = root->left;
        root->left = NULL;
        invertTree(root->right);
    }
    return root;     
}


struct node* invertTree2(struct node* root) {
    if(root == NULL)
    {
        return NULL;
    }
    
    struct node* left = invertTree2(root->left);
    struct node* right = invertTree2(root->right);
    
    root->left = right;
    root->right = left;
    
    return root;
}
      
int main() 
{
  struct node *root = NULL;
   
  root = new node(20);
  root->left = new node(15);
  root->right = new node(25);
  root->left->left = new node(10);
  root->left->right = new node(16);
  root->right->left = new node(23);
  root->right->right = new node(30);
  
  cout << endl;
  inOrder(root);
  
 // root = invertTree(root);
  
  root = invertTree2(root);
  
  cout << endl;
  inOrder(root);
  
}
