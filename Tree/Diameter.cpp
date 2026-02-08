#include <bits/stdc++.h>
using namespace std;
  
struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
struct node * insertData()
{
	struct node* root = newNode(20);   
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
  //  root->right->left = newNode(21);
    root->right->right = newNode(25);
	return root;   
}

void inorder(node *r){
	if(r != NULL){
		inorder(r->left);
		cout << r->data << "\t";		
		inorder(r->right);
	}
}

int height(struct node* node)
{
    if (node == NULL)
        return 0;
 
    return 1 + max(height(node->left), height(node->right));
}

int diameter(struct node* tree)
{
    if (tree == NULL)
        return 0;

    int lheight = height(tree->left);
    int rheight = height(tree->right);
 
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
 
    return max(lheight + rheight, max(ldiameter, rdiameter));
}
 


////////////////////////////////////////////////////////  
int main()
{
    struct node* root = insertData();
    inorder(root);  
    
    cout << "Diameter : " << diameter(root);
    return 0;
}
