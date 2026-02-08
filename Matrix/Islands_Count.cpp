/*
/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the number of islands in grid. If there is no island, return 0.

Input :
{ { 1, 1, 0, 0, 0 },
 { 0, 1, 0, 0, 1 },
 { 1, 0, 0, 1, 1 },
 { 0, 0, 0, 0, 0 },
 { 1, 0, 1, 0, 1 } };

Output : 3			                     
*/
*/
#include <bits/stdc++.h>
using namespace std;
 
void calling(vector<vector<int>> &grid, int i, int j)
{
    if(i<0 || j<0 || i==grid.size() || j==grid[0].size())
    {
        return;
    }
    if(grid[i][j] == 0)
    {
        return;
    }
    grid[i][j]=0;
    calling(grid, i-1, j);
    calling(grid, i, j+1);
    calling(grid, i+1, j);
    calling(grid, i, j-1); 
}

int numIslands(vector<vector<int>> &grid) {
    int n =grid.size();
    int m = grid[0].size();
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                calling(grid,i,j);
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = { { 1, 1, 0, 0, 0 },
			                     { 0, 1, 0, 0, 1 },
			                     { 1, 0, 0, 1, 1 },
			                     { 0, 0, 0, 0, 0 },
			                     { 1, 0, 1, 0, 1 } };
 
     cout << "Number of islands is: " << numIslands(grid);
     return 0;
}
