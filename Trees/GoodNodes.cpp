#include "Tree.cpp"


void solve(TreeNode* root, int max_, int& count)
{
    if(!root)
        return;
    
    if(root->val>=max_)
    {        
        count++;
    }
        
    max_=max(max_, root->val);
    solve(root->left,max_,count);
    solve(root->right,max_,count);
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

  int count = 0;
  solve(root, 0, count);   
  cout << count;
  return 0;
}
