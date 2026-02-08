/*
671. Second Minimum Node In a Binary Tree

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

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
	struct node* root = newNode(2);   
    root->left = newNode(2);
    root->right = newNode(5);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
	return root;   
}


set<int> s;

void helper(struct node* root)
{
    if(root != NULL){        
	    s.insert(root->data);
	    helper(root->left);
	    helper(root->right);    
    }
}

int findSecondMinimumValue(struct node* root) {
    if(root == NULL)
        return -1;
    
    helper(root);      

    if(s.size() > 1)
    {
    	auto it = s.begin();
		it++;
		return *it;	
	}	

    return -1;
}

int main()
{
	
	struct node* root = insertData();
	
	cout << findSecondMinimumValue(root);
	
	return 0;
}
