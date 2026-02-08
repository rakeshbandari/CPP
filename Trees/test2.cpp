#include<bits/stdc++.h>
using namespace std;
struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

struct node * insert(int data)
{
	struct node *new_node = new node();
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;	
	
	return new_node;
}

void inorder(struct node *root)
{	
	if(root)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

struct node * LCA(struct node *root, int n1, int n2)
{
	if(root == NULL) return NULL;
	
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
  

    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
  
    return root;
}



bool getPath(node* root, vector<int>& arr, vector<int>& arrBool, int x, int dir)
{
    if (!root)
        return false;

    arr.push_back(root->data);
 	arrBool.push_back(dir);
 	
    if (root->data == x)
        return true;
 
    if (getPath(root->left, arr, arrBool, x, 1) || getPath(root->right, arr, arrBool, x, 0))
        return true;
 
    arr.pop_back();
    arrBool.pop_back();
    
    return false;
}
 
void display(vector<int> arr)
{
	cout << endl;
	for(int i : arr)
	{
		cout << i << " ";	
	}
	cout << endl;	
} 
void printPathBetweenNodes(node* root, int n1, int n2)
{
    vector<int> path1;
    vector<int> path2;
    vector<int> bool1;
    vector<int> bool2;
 
    getPath(root, path1, bool1, n1, -1);
    getPath(root, path2, bool2, n2, -1);
 
    int intersection = -1;
	display(path1);
	display(bool1);
	display(path2);
	display(bool2);
	
	
    int i = 0, j = 0;
    while (i != path1.size() || j != path2.size()) {
 
        if (i == j && path1[i] == path2[j]) {
            i++;
            j++;
        }
        else {
            intersection = j - 1;
            break;
        }
    }
 
    for (int i = path1.size() - 1; i > intersection; i--)
        cout << path1[i] << " ";
 
    for (int i = intersection; i < path2.size(); i++)
        cout << path2[i] << " ";
}
 
/*
	  3
   2    5
 1	  4   8
 
*/
int main()
{
	struct node *root = insert(3);
	root->left = insert(2);
	root->right = insert(5);
	root->left->left = insert(1);
	root->right->left = insert(4);
	root->right->right = insert(8);
	
	inorder(root);
	
	struct node *res = LCA(root, 1, 4);
	
	cout << endl << res->data;
	
	res = LCA(root, 1, 5);
	
	cout << endl << res->data;
	
	res = LCA(root, 4, 8);
	
	cout << endl << res->data;
	
	cout << endl << endl;
	
	printPathBetweenNodes(root, 4, 8);
	return 0;
}
