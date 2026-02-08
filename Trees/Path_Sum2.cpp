#include "Tree.cpp"

/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.

*/

vector<vector<int>> result;

vector<int> res;
    
void helper(TreeNode* root, int targetSum) {
    
    if(root==NULL)
    return;
    
    res.push_back(root->val);
    
    if(root->left == NULL && root->right == NULL)
    {
        if(root->val == targetSum)
        result.push_back(res);
        res.pop_back();
        return;
    } 
    
    helper(root->left, targetSum - root->val);
    helper(root->right, targetSum - root->val); 
    
    res.pop_back();
    
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    helper(root, targetSum);
    return result;
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
  
  pathSum(root,target);
  
  for(int i=0; i < result.size();i++)
  {
  	for(int j=0; j < result[i].size();j++)
  	cout << result[i][j] << "->";
	cout << endl;   
  }
  
  return 0;
}
