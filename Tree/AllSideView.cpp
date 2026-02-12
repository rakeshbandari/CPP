#include "Tree.cpp"

////////////////////////////////////////////////////////
void dfs(TreeNode* root, int level, vector<int>& result) {
    if (!root) return;

    // If this is first time visiting this level
    if (level == result.size())
        result.push_back(root->val);

    dfs(root->left, level + 1, result);
    dfs(root->right, level + 1, result);
}

void leftSideView(TreeNode* root) {
    vector<int> result;
    dfs(root, 0, result);

    cout << std::endl;
    for(int i=0; i<result.size();i++)
    	cout << result[i] << " ";      
}

////////////////////////////////////////////////////////

void rightSide(TreeNode* root, int level, vector<int>& result) {
    if (!root) return;

    // First time visiting this level
    if (level == result.size())
        result.push_back(root->val);

    rightSide(root->right, level + 1, result);
    rightSide(root->left, level + 1, result);
}

void rightSideView(TreeNode* root) {
    vector<int> result;
    rightSide(root, 0, result);
    
    cout << std::endl;
    for(int i=0; i<result.size();i++)
    cout << result[i] << " "; 
}


///////////////////////////////////////////////////

void topView(TreeNode* root) {
    vector<int> result;
    if (!root) return;

    // HD -> node value
    map<int, int> mp;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        TreeNode* node = temp.first;
        int hd = temp.second;

        // Store first node for each HD
        if (mp.find(hd) == mp.end()) {
            mp[hd] = node->val;
        }

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    // Store results in order of HD
    for (auto it : mp) {
        result.push_back(it.second);
    }
    
    cout << std::endl;
    for(int i=0; i<result.size();i++)
    cout << result[i] << " ";

}

/////////////////////////////////////////////////////

void bottomView(TreeNode* root) {
    vector<int> result;
    if (!root) return;

    map<int, int> mp;  // HD -> node value

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        TreeNode* node = temp.first;
        int hd = temp.second;

        // Overwrite value for each HD
        mp[hd] = node->val;

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    // Store values in sorted HD order
    for (auto it : mp) {
        result.push_back(it.second);
    }

    cout << std::endl;
    for(int i=0; i<result.size();i++)
    cout << result[i] << " ";
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

  leftSideView(root);
  rightSideView(root);
  topView(root);
  bottomView(root);   
  
  return 0;
}
