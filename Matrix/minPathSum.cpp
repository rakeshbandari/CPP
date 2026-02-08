#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int> > &grid) {
    int m = grid.size();
	int n = grid[0].size();

	int dp[m][n];
	dp[0][0] = grid[0][0];

	for(int i = 1; i < n; i++){      
		dp[0][i] = dp[0][i - 1] + grid[0][i]; 
	}
	for(int i = 1; i < m; i++){     
		dp[i][0] = dp[i - 1][0] + grid[i][0]; 
	}

	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
		}
	}
	return dp[m - 1][n - 1];
} 
int main()
{
	int gt[3][3] = {{1,3,1},{1,5,1},{4,2,1}};
	//vector<vector<int> > grid = {{1,3,1},{1,5,1},{4,2,1}};
	
    vector<vector<int> > grid;
	for(int i=0;i<3;i++){
    	vector<int> v;
		for(int j=0;j<3;j++){
			v.push_back(gt[i][j]);
		}
		grid.push_back(v);		
	}				            
    	
    cout << minPathSum(grid);    
    
    getchar();
    return 0;
}
