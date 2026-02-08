#include "Tree.cpp"

vector<int> v;
bool isValidBST(TreeNode* root) {
	
	if (root == NULL) 
		return true;
	
	bool left = isValidBST(root->left);
	
	v.push_back(root->val);
	
	if (v.size() >= 2 && v[v.size() - 1] <= v[v.size() - 2]) 
	{		
    	return false;   	
	}	
	
	bool right = isValidBST(root->right);
	
	return left && right;
}
    
int main()
{
	
  TreeNode *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "\nInorder traversal: ";
  inOrder(root);
  	
  cout << "\nisValidBST: " << isValidBST(root);
 
    return 0;
}
