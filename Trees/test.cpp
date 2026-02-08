#include "BST.cpp"
int main()
{
        BST myBST;
                
                
      
        int h = myBST.getHeight();
        cout << "the height of this BSt is : " << h << endl;

        TreeNode * mx = myBST.getMaxNode();
        cout << "max value: " << mx->val << endl;

        TreeNode * mi = myBST.getMinNode();
        cout << "min value: " << mi->val << endl;

        bool isbal = myBST.isBalanced();
        if (isbal)
                cout << "BST is balanced! " << endl;
        else
                cout << "BST is not balanced! " << endl;

        cout << " in-order traverse is : " << endl;
        myBST.inOrder();cout << endl;
        cout << " pre-order traverse is : " << endl;
        myBST.preOrder();cout << endl;
        cout << " post-order traverse is : " << endl;
        myBST.postOrder();cout << endl;
}
