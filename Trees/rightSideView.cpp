#include "Tree.cpp"

////////////////////////////////////////////////////////
int maxDepth(TreeNode *root) 
{
    if(root == NULL) return 0;
    
    if(root->left == NULL && root->right == NULL) return 1;
    
    int left = maxDepth(root->left) + 1;
    int right = maxDepth(root->right) + 1;
    
    return max(left, right);         
}
 
vector<int> da;
void printLevelOrder(TreeNode *head, int level){
	if(head == NULL) 
		return ;
	if(level == 1){
		da.push_back(head->val);
	}	
	printLevelOrder(head->left, level-1);
	printLevelOrder(head->right, level-1);		
}

void rightSideView(TreeNode *root){
    int len = maxDepth(root);
	for(int i=1;i<=len;i++)
	{
		printLevelOrder(root, i);
		 if(da.size() >= 1)
		 cout << da[da.size()-1] << " ";	 
		 da.clear();
    }	
}

////////////////////////////////////////////////////////

void rightu(TreeNode * root, int* maxl, int l, vector<int>&v)
{
    if(!root)
    return;
    
    if(*maxl < l)
    {
        *maxl = l;
        v.push_back(root->val);
    }
    
    rightu(root->right, maxl, l+1, v);
    rightu(root->left, maxl, l+1, v);
}
    
void rightSideView2(TreeNode *root){
	
	vector<int> v;
	
    int maxl=0;
    
    rightu(root, &maxl, 1, v);
    
    for(int i=0; i<v.size();i++)
    	cout << v[i] << " ";    	
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

  rightSideView2(root);   
  
  return 0;
}
