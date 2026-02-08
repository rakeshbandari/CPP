/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
 
*/

#include <bits/stdc++.h>
using namespace std;

////////////   Normal Method //////////////////////
int solve(int m, int n, int i, int j){
    
	if(i==m-1 or j==n-1)
		return 1; // destination reached.
    
	if(i>=m or j>=n)
		return 0; //out of bound
    
	else{
        return (solve(m,n,i+1,j) + solve(m,n,i,j+1)); // travelling to the possible neighbours i.e., down and right cells.
    }
}

int uniquePaths(int m, int n) {
    return  solve(m,n,0,0);
} 

////////////   using DP Method  Efficient //////////////////////

int solve(int m, int n, int i, int j, vector<vector<int>> &dp){
    if(i==m-1 or j==n-1)
		return 1;
    
	if(i>=m or j>=n)
		return 0;
    
	if(dp[i][j]!=-1)
		return dp[i][j]; //checking if its already visited.
    
	else{
        return dp[i][j]= (solve(m,n,i+1,j,dp) + solve(m,n,i,j+1,dp)); 
    }
}
int uniquePaths2(int m, int n) {
    vector <vector<int>> dp(m+1, vector<int> (n+1,-1)); // Initializing the dp matrix with -1 so that we know if it is visited or not.
    return  solve(m,n,0,0,dp);
}
    
int main()
{
    int m = 3, n = 7;
    cout << "\nuniquePaths : " << uniquePaths(m, n);
    cout << "\nuniquePaths : " << uniquePaths2(m, n);
    return 0;
}
