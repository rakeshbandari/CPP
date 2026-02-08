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

void inorder(node *r){
	if(r != NULL){
		inorder(r->left);
		cout << r->data << "\t";		
		inorder(r->right);
	}
}

vector<int> longestPath(node* root)
{
    if (root == NULL) {
        vector<int> temp = {};
        return temp;
    }     
    vector<int> rightvect = longestPath(root->right);     
    vector<int> leftvect = longestPath(root->left); 
    if (leftvect.size() > rightvect.size())
        leftvect.push_back(root->data); 
    else
        rightvect.push_back(root->data);     
    return (leftvect.size() > rightvect.size() ? leftvect : rightvect);
}
 


////////////////////////////////////////////////////////  
int main()
{
    struct node* root = insertData();
    inorder(root);  
    
    vector<int> result = longestPath(root);
    
    cout << endl << "Result : ";
    for(int i=0;i<result.size();i++)
    	cout << result[i] << "->";
    return 0;
}
