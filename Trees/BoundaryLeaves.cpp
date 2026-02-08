#include "Tree.cpp"

void printLeaves(TreeNode* root)
{
    if (root == NULL)
        return;
  
    printLeaves(root->left);
  
    if (!(root->left) && !(root->right))
        cout << root->val << " ";
  
    printLeaves(root->right);
}

void printBoundaryLeft(TreeNode* root)
{
    if (root == NULL)
        return;
  
    if (root->left) {  
        cout << root->val << " ";
        printBoundaryLeft(root->left);
    }
    else if (root->right) {
        cout << root->val << " ";
        printBoundaryLeft(root->right);
    }
}

void printBoundaryRight(TreeNode* root)
{
    if (root == NULL)
        return;
  
    if (root->right) {
        printBoundaryRight(root->right);
        cout << root->val << " ";
    }
    else if (root->left) {
        printBoundaryRight(root->left);
        cout << root->val << " ";
    }
}
  
void printBoundary(TreeNode* root)
{
    if (root == NULL)
        return;
  
    cout << root->val << " ";
    printBoundaryLeft(root->left);
    printLeaves(root->left);
	printLeaves(root->right);
    printBoundaryRight(root->right);
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

  printBoundary(root);   
  
  return 0;
}
