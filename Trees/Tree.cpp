#include <bits/stdc++.h>
using namespace std;
 
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};
 
TreeNode* newNode(int item)
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->val = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
TreeNode* insert(TreeNode* node, int key)
{
    if (node == NULL)
        return newNode(key);
 
    if (key < node->val)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
     
    return node;
}
 
TreeNode* minValueNode(TreeNode* node)
{
    TreeNode* current = node;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}


TreeNode* manValueNode(TreeNode* node)
{
    TreeNode* current = node;
 
    while (current && current->right != NULL)
        current = current->right;
 
    return current;
}

void preOrder(TreeNode* root)
{
    if (root != NULL) 
	{
		cout << root->val << " ";
        preOrder(root->left);        
        preOrder(root->right);
    }
}
 
void inOrder(TreeNode* root)
{
    if (root != NULL) 
	{
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

void postOrder(TreeNode* root)
{
    if (root != NULL) 
	{
        postOrder(root->left);        
        postOrder(root->right);
        cout << root->val << " ";
    }
}
