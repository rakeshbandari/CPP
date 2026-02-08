#include "Tree.cpp"

bool ans = true;

bool isMirror(TreeNode* root1, TreeNode* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
 
    if (root1 && root2 && root1->val == root2->val)
    {
	    return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
    
    return false;
}
bool isSymmetric(TreeNode* root) {
	
	return isMirror(root, root);
}

int main()
{
    /* 
	Let us create following BST
            1
           /  \
        2      2
       / \    /  \
     3    4  4    3 
 */
    TreeNode* root = NULL;    
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

	cout << "isSymmetric : " << isSymmetric(root);
 

    return 0;
}
