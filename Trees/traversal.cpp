#include "Tree.cpp"

void preOrder(TreeNode* root)
{
    if (root != NULL) 
	{
		cout << root->val << " ";
        preOrder(root->left);        
        preOrder(root->right);
    }
}
 
void inOrder(TreeNode* root)
{
    if (root != NULL) 
	{
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

void postOrder(TreeNode* root)
{
    if (root != NULL) 
	{
        postOrder(root->left);        
        postOrder(root->right);
        cout << root->val << " ";
    }
}
 
int main()
{
    /* 
	Let us create following BST
            50
           /  \
        30     70
       / \    /  \
     20  40  60  80 
   */
    TreeNode* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    cout << "\nPreorder : ";
    preOrder(root);
    cout << "\nInorder : ";
    inOrder(root);
    cout << "\nPostorder : ";
	postOrder(root);
 

    return 0;
}
