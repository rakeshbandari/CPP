#include "Tree.cpp"
#include <bits/stdc++.h>
/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    } else if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    
    int ht = INT_MAX;
    if (root->left != nullptr) {
        ht = min(minDepth(root->left), ht);
    }
    
    if (root->right != nullptr) {
        ht = min(minDepth(root->right), ht);
    }
    
    return 1 + ht;
}

int main()
{
	/*
			   20
			  /  \
		    8     22
	  	  /  \	   \	
		4     12     14
		     / \
		  10   14 	
		  
	*/	  
    
    TreeNode *root           = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
  
  cout << endl << minDepth(root);
  return 0;
}
