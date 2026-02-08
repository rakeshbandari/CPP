#include "Tree.cpp"

vector<int> longestPath(TreeNode* root) {
    if (root == NULL) {
        vector<int> temp = {};
        return temp;
    }
     
    vector<int> rightvect = longestPath(root->right);
     
    vector<int> leftvect = longestPath(root->left);
 
    if (leftvect.size() > rightvect.size())
        leftvect.push_back(root->val); 
    else
        rightvect.push_back(root->val);
     
    return (leftvect.size() > rightvect.size() ? leftvect : rightvect);
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

  vector<int> result = longestPath(root);
  
  for(int i : result)
   cout << i << "->";  
  
  return 0;
}
