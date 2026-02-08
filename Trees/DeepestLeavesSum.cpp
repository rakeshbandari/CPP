#include "Tree.cpp"

//////////////////////////////////////////////////////////
int sum=0;
int height(TreeNode* node)
{
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}

void traversal(TreeNode* root, int ht)
{
    if(root == NULL)return;
    
    if (ht == 1)
        sum += root->val;
    
    traversal(root->left, ht-1);
    traversal(root->right, ht-1);
    
}
int deepestLeavesSum(TreeNode* root) {
    int ht = height(root);
    
    traversal(root,ht);
        
    return sum;
}
//////////////////////////////////////////////////////////

// Optimized

map<int,int> mp;
void helper(TreeNode* root,int level){
    if(root==NULL)return;
    mp[level]+=root->val;
    helper(root->left,level+1);
    helper(root->right,level+1);
}
int deepestLeavesSum2(TreeNode* root) {
    helper(root,1);
    int sum;
    for(auto itr=mp.begin();itr!=mp.end();itr++){
         sum=itr->second;
    }
    return sum;
}


//////////////////////////////////////////////////////// 

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

  cout << deepestLeavesSum2(root);   
  
  return 0;
}
