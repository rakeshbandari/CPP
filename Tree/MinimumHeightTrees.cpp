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

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
{
    if(n==1)
    {
        vector<int> ans;
        ans.push_back(0);
        return ans;
    }
    unordered_map<int, int> A;
    int no_edges = edges.size();
    for(int i=0; i<no_edges; i++)
    {
        A[edges[i][0]]++;
        A[edges[i][1]]++;
    }
    
    
    unordered_map<int, int>::iterator itr;

    for (itr = A.begin(); itr != A.end(); ++itr) {
        cout << '\n' << itr->first
             << '\t' << itr->second;
    }
    
    queue<int> Q;
    for(int i=0; i<n; i++)
    {
        if(A[i]==1)
            Q.push(i);
    }
    while(n>2)
    {
        int qs = Q.size();
        n-=qs;
        for(int i=0; i<qs;i++)
        {
            int t = Q.front();
            Q.pop();
            for(int j=0; j<no_edges; j++)
            {
                if(edges[j][0]==t)
                {
                    A[edges[j][1]]--;
                    if(A[edges[j][1]]==1)
                        Q.push(edges[j][1]);
                }
                else {
                    if(edges[j][1]==t)
                    {
                        A[edges[j][0]]--;
                        if(A[edges[j][0]]==1)
                            Q.push(edges[j][0]);
                    }
                }
            }
        }
    }
    vector<int> ans;
    while(!Q.empty())
    {
        ans.push_back(Q.front());
        Q.pop();
    }
    return ans;        
}

int main()
{
	vector<vector<int>> mat = {{1,0},{1,2},{1,3}};
	
	vector<int> result = findMinHeightTrees(4, mat);
	
	return 0;
}
