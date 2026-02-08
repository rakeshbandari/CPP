#include "Tree.cpp"

int height(TreeNode* node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

void printGivenLevel(TreeNode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->val << " ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(TreeNode* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
      printGivenLevel(root, i);
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

  cout << "Level Order traversal of binary tree is \n";
  printLevelOrder(root);
  
  return 0;
}
