#include "Tree.cpp"

TreeNode *lca(TreeNode* root, int n1, int n2)
{
    if (root == NULL) return NULL;
  

    if (root->val > n1 && root->val > n2)
        return lca(root->left, n1, n2);
  

    if (root->val < n1 && root->val < n2)
        return lca(root->right, n1, n2);
  
    return root;
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
			

    int n1 = 10, n2 = 14;
    TreeNode *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->val);
  
    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->val);
  
    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->val);
    
  return 0;
}
