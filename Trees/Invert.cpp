#include "Tree.cpp"

TreeNode* invertTree(TreeNode* root) {
    if(root == NULL)
    {
        return NULL;
    }
    
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    
    root->left = right;
    root->right = left;
    
    return root;
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

  inOrder(root);
  cout << endl;
  invertTree(root);
  cout << endl;
  inOrder(root);
  
  return 0;
}
