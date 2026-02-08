#include <iostream>
#include <conio.h>
using namespace std;

struct TreeNode{
    TreeNode(int value): val(value), left(NULL), right(NULL) {}
    int val;
    TreeNode *left;
    TreeNode *right;
};

/////////////////////////////////////////////////////////////////////////////////////////
// BST class
class BST{
private:
    TreeNode *_root;
    void insert(TreeNode *root, int data);    
    bool isBalanced(TreeNode *root);
    int  getHeight(TreeNode *root);
    void deleteBST(TreeNode *root);
    void inOrder(TreeNode * root);
    void preOrder(TreeNode * root);
    void postOrder(TreeNode * root);    
public:

    BST();  // constructor     
    ~BST();     // destructor

    void insert(int data)
	{ 
		insert(_root, data);
	}
	void insertRandomData(TreeNode * root);

    int getHeight(){return getHeight(_root);}
    TreeNode * getMaxNode();
    TreeNode * getMinNode();

    void deleteBST() {deleteBST(_root);}

    bool isBalanced(){return isBalanced(_root);}

    void inOrder() {inOrder(_root);}
    void preOrder(){preOrder(_root);}
    void postOrder(){postOrder(_root);}
};

/////////////////////////////////////////////////////////////////////////////////////////
BST::BST()
{
   _root = NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::insert(TreeNode *root, int data)
{
	if(root == NULL)
	{
		root = new TreeNode(data);
		return;
	}
	if(data == root->val)
		return;
	if(data > root->val)
		insert(root->right, data);
	else
		insert(root->left, data);
}

/////////////////////////////////////////////////////////////////////////////////////////
int BST::getHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;
        
    return 1 + max(getHeight(root->left) , getHeight(root->right));
}

/////////////////////////////////////////////////////////////////////////////////////////
bool BST::isBalanced(TreeNode *root)
{
    if (root == NULL)
        return false;
        
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (abs(leftHeight - rightHeight) > 1)
        return false;
    return true;
}

/////////////////////////////////////////////////////////////////////////////////////////
TreeNode * BST::getMaxNode()
{
    if(_root == NULL)
    {
        cout <<  " the BST is empty!" << endl;
        return NULL;
    }
    TreeNode * treeNode = _root;
    while(treeNode->right)
        treeNode = treeNode ->right;
    return treeNode;
}

/////////////////////////////////////////////////////////////////////////////////////////
TreeNode * BST::getMinNode()
{
    if(_root == NULL)
    {
        cout <<  " the BST is empty!" << endl;
        return NULL;
    }
    TreeNode * treeNode = _root;
    while(treeNode->left)
        treeNode = treeNode ->left;
    return treeNode;
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::deleteBST(TreeNode *root) 
{
    if (root == NULL) return; 

    deleteBST(root->left); 
    deleteBST(root->right);  

    delete root;
}

/////////////////////////////////////////////////////////////////////////////////////////
BST::~BST()
{
    deleteBST();
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::inOrder(TreeNode * root)
{
    if (root != NULL){
	    inOrder(root->left);
	    cout << root->val << " " ;
	    inOrder(root->right);    	
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::preOrder(TreeNode * root)
{
    if (root != NULL){
	    cout << root->val << " " ;
		preOrder(root->left);	    
	    preOrder(root->right);    	
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::postOrder(TreeNode * root)
{
    if (root != NULL)
	{	    
		postOrder(root->left);	    
	    postOrder(root->right);    	
	    cout << root->val << " " ;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////

