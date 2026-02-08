#include <bits/stdc++.h>
using namespace std;
  
struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
struct node * insertData()
{
	struct node* root = newNode(20);   
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
  //  root->right->left = newNode(21);
    root->right->right = newNode(25);
	return root;   
}
////////////////////////////////////////////////////////
int maxDepth(struct node *root) 
{
    if(root == NULL) return 0;
    
    if(root->left == NULL && root->right == NULL) return 1;
    
    int left = maxDepth(root->left) + 1;
    int right = maxDepth(root->right) + 1;
    
    return max(left, right);         
}
 
vector<int> da;
void printLevelOrder(struct node *head, int level){
	if(head == NULL) 
		return ;
	if(level == 1){
		da.push_back(head->data);
	}	
	printLevelOrder(head->left, level-1);		
	printLevelOrder(head->right, level-1);		
}

void rightSideView(struct node *root){
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

void rightu(struct node * root, int* maxl, int l, vector<int>&v)
{
    if(!root)
    return;
    
    if(*maxl < l)
    {
        *maxl = l;
        v.push_back(root->data);
    }
    
    rightu(root->right, maxl, l+1, v);
    rightu(root->left, maxl, l+1, v);
}
    
void rightSideView2(struct node *root){
	
	vector<int> v;
	
    int maxl=0;
    
    rightu(root, &maxl, 1, v);
    
    for(int i=0; i<v.size();i++)
    	cout << v[i] << " ";    	
}

////////////////////////////////////////////////////////  
int main()
{
    struct node* root = insertData();
    rightSideView2(root);
  
    return 0;
}
