#include "Tree.cpp"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL) return NULL;
    if(root==p || root==q) return root;
    
    root->left = lowestCommonAncestor(root->left, p, q);
    root->right = lowestCommonAncestor(root->right, p, q);
    
    if(root->left!=NULL && root->right!=NULL) return root;
    else
        return (root->left?root->left:root->right);
}

int main()
{
/*
		    1
		  /   \
	    2      2
  	  /  \	  / \	
	3     4  4   3
	     / \
	  	4   7 	
	  
*/	  		
  TreeNode *root = NULL;

  root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(2);
  root->left->left = newNode(3);
  root->left->right = newNode(4);
  root->right->left = newNode(4);
  root->right->right = newNode(3);
  
  
  TreeNode *result = lowestCommonAncestor(root, root->left->right, root->right->right);
  
  cout <<  result->val;
  return 0;
}
