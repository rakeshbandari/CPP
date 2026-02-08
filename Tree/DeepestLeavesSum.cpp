/*
1302. Deepest Leaves Sum
Given the root of a binary tree, return the sum of values of its deepest leaves.
*/

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
//////////////////////////////////////////////////////////
int sum=0;
int height(struct node* node)
{
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}

void traversal(struct node* root, int ht)
{
    if(root == NULL)return;
    
    if (ht == 1)
        sum += root->data;
    
    traversal(root->left, ht-1);
    traversal(root->right, ht-1);
    
}
int deepestLeavesSum(struct node* root) {
    int ht = height(root);
    
    traversal(root,ht);
        
    return sum;
}
//////////////////////////////////////////////////////////

// Optimized

map<int,int> mp;
void helper(struct node* root,int level){
    if(root==NULL)return;
    mp[level]+=root->data;
    helper(root->left,level+1);
    helper(root->right,level+1);
}
int deepestLeavesSum2(struct node* root) {
    helper(root,1);
    int sum;
    for(auto itr=mp.begin();itr!=mp.end();itr++){
         sum=itr->second;
    }
    return sum;
}


////////////////////////////////////////////////////////  
int main()
{
    struct node* root = insertData();
    
    cout << "deepestLeavesSum : " << deepestLeavesSum(root);
    return 0;
}
