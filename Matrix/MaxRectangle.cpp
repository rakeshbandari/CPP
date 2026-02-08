#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &matrix){
	cout << endl << endl;
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[0].size();j++)
			cout << matrix[i][j] << " ";
		cout << endl;	
	}
}


int maximalRectangle(vector<vector<int>>& matrix) {
    if(matrix.size()==0)
        return 0;
    int m=matrix.size(), n=matrix[0].size();
    vector<vector<int>> dp(m+1,vector<int>(n,0));
    vector<vector<int>> mat(m+1,vector<int>(n,0));
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat[i][j] = matrix[i-1][j]==1 ? 1 : 0;
        }
    }
    
    display(mat);
    
    int res=0;
    
    for(int i=1;i<=m;i++)
    {
        stack<int> st;
        vector<int> left(n);
        int leftbound=-1;
        for(int j=0; j<n; j++)
        {
            if(mat[i][j]==1)
            {
                mat[i][j] = 1 + mat[i-1][j];
                
                while(!st.empty() && mat[i][st.top()] >= mat[i][j])
                    st.pop();
                
				int val = leftbound;
                
				if(!st.empty())
                    val = max(val,st.top());
                
				left[j] = val;
            }
            else
            {
                left[j] = 0;
                leftbound = j;
            }
            st.push(j);
        }
        while(!st.empty())
            st.pop();
        int rightbound=n;
        for(int j=n-1;j>=0;--j)
        {
            if(mat[i][j]!=0)
            {
                while(!st.empty() && mat[i][st.top()]>=mat[i][j])
                    st.pop();
                int val=rightbound;
                if(!st.empty())
                    val=min(val,st.top());
                dp[i][j]=mat[i][j]*((val-1)-(left[j]+1)+1);
                res=max(res,dp[i][j]);
                st.push(j);
            }
            else
            {
                dp[i][j]=0;
                rightbound=j;
            }
        }
    }
    display(mat);
    return res;
}
int main()
{
	vector<vector<int>> matrix = {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
	
	
//	display(mat);
	
	cout << endl << endl << "Result : " << maximalRectangle(matrix);
    
    return 0;
}
