#include "Tree.cpp"

/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

*/


bool hasPathSum(TreeNode* root, int targetSum) {
    
    if(root==NULL)
    return false;
    
    if(root->val == targetSum && root->left == NULL && root->right == NULL)
        return true;
    
    bool lf=hasPathSum(root->left, targetSum - root->val) ;
    bool rf=hasPathSum(root->right, targetSum - root->val) ;
    
    return lf || rf;
}

int main()
{
/*
		    8
		  /  \
	    3     10
  	  /  \	   \	
	1     6     14
	     / \
	  	4   7 	
	  
*/	  		
  TreeNode *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  int target = 32;
  
  cout << hasPathSum(root,target);
  
  return 0;
}
