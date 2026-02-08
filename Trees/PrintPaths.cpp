#include "Tree.cpp"

void printArray(int ints[], int len)
{
  int i;
  for (i=0; i<len; i++) {    
    cout << ints[i] << " ";
  }
  cout << endl;
} 
 
void _printPaths(TreeNode *root, int p[], int len)
{
	if(root == NULL)
	return;
	
	p[len] = root->val;
	len++;
	
	if(root->left == NULL && root->right == NULL)
	printArray(p,len);
	
	_printPaths(root->left, p, len);
	_printPaths(root->right, p, len);
}

void printPaths(TreeNode *root)
{
	int p[1000];
	_printPaths(root, p, 0);
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

  printPaths(root);   
  
  return 0;
}
