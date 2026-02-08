/*
LeetCode 572. Subtree of Another Tree

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

*/

#include "Tree.cpp"

bool sameTree(TreeNode* root, TreeNode* subRoot)
{
    if(root == NULL || subRoot == NULL) 
	  return root == subRoot;

    return (root->val == subRoot->val) && sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
}
            
bool isSubtree(TreeNode* root, TreeNode* subRoot) 
{
     
    if(root == NULL)
        return false;
    
    if(subRoot == NULL)
        return true;
    
    if(sameTree(root, subRoot))
        return true;
    
    return (isSubtree(root->left, subRoot)) || (isSubtree(root->right, subRoot));        
}
 
int main()
{
    /* 
	Let us create following BST
            50
           /  \
        30     70
       / \    /  \
     20  40  60  80 
     
     subroot
         30
        /  \
	  20   40	 
   */
    TreeNode* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
 	TreeNode* sub = NULL;
 	sub = insert(sub, 30);
 	sub = insert(sub, 20);
 	sub = insert(sub, 40);
 	
	cout << (isSubtree(root, sub)? "True" : "False");

    return 0;
}
