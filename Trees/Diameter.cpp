#include "Tree.cpp"

///// Optimized ////
unordered_map<TreeNode*, int> heights;
int height2(TreeNode* root)
{
	if(heights.find(root) != heights.end())
		return heights[root];
	
    if (root == NULL)
        return 0;
    
    int left = height2(root->left);
    int right = height2(root->right);
    
    heights[root] = 1 + max(left, right);
    return heights[root];
}
//////////////////////

int height(TreeNode* node)
{
    if (node == NULL)
        return 0;
 
    return 1 + max(height(node->left), height(node->right));
}

int diameter(TreeNode* tree)
{
    if (tree == NULL)
        return 0;

    int lheight = height(tree->left);
    int rheight = height(tree->right);
 
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
 
    return max(lheight + rheight, max(ldiameter, rdiameter));
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
    
    cout << "Diameter : " << diameter(root);
    return 0;	
}
