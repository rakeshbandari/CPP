#include <bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    vector<Node*> child;
 
    Node(int x) : data(x)
    {
    }
};
 
void printPath(vector<int> vec)
{
    for (int ele : vec) {
        cout << ele << " ";
    }
    cout << endl;
}
 
void printAllRootToLeafPaths(Node* root, vector<int> vec)
{
    if (!root)
        return;
 
    vec.push_back(root->data);
 
    if (root->child.empty()) {
 
        printPath(vec);
 
        vec.pop_back();
        return;
    }
 
    for (int i = 0; i < root->child.size(); i++) 
        printAllRootToLeafPaths(root->child[i], vec);
}
 
void printAllRootToLeafPaths(Node* root)
{
    if (!root)
        return;
 
    vector<int> vec;
 
    printAllRootToLeafPaths(root, vec);
}
 
int main()
{
	
    Node* root = new Node(1);
    (root->child).push_back(new Node(2));
    (root->child).push_back(new Node(3));
    (root->child[0]->child).push_back(new Node(4));
    (root->child[1]->child).push_back(new Node(5));
    (root->child[1]->child).push_back(new Node(6));
    (root->child[1]->child[1]->child).push_back(new Node(7));
    (root->child[1]->child[1]->child).push_back(new Node(8));
 
    printAllRootToLeafPaths(root);
 
    return 0;
}
