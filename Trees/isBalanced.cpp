#include "Tree.cpp"

bool ans = true;

int depth(TreeNode *root)
{
    if(root==NULL)
        return 0;
    
    int ld = depth(root->left);
    int rd = depth(root->right);
    
    if(abs(ld-rd)>1)
        ans = false;
    
    return 1 + max(ld, rd);
}
    
bool isBalanced(TreeNode* root) {
    ans= true;
    
    depth(root);
    
    return ans;
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
 

	cout << "isBalanced : " << isBalanced(root);
 

    return 0;
}
