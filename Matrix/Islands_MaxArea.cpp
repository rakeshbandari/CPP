/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

Input :
{ { 1, 1, 0, 0, 0 },
 { 0, 1, 0, 0, 1 },
 { 1, 0, 0, 1, 1 },
 { 0, 0, 0, 0, 0 },
 { 1, 0, 1, 0, 1 } };

Output : 3			                     
*/

#include <bits/stdc++.h>
using namespace std;
 
int max_area = 0;    
void calling(vector<vector<int>>& grid, int i, int j, int &area){
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
        return;
    }
    if(grid[i][j] == 0){
        return;
    }
    
    area++;
    
    grid[i][j] = 0;
    calling(grid, i, j+1, area);
    calling(grid, i+1, j, area);
    calling(grid, i, j-1, area);
    calling(grid, i-1, j, area);
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int M = grid.size();
    int N = grid[0].size();
    
    int area = 0;
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            if(grid[i][j] == 1)
            {
                area = 0;
                calling(grid, i, j, area);
                if(area > max_area)
                    max_area = area;                    
            }          
    return max_area;
}

int main()
{
    vector<vector<int>> grid = { { 1, 1, 0, 0, 0 },
			                     { 0, 1, 0, 0, 1 },
			                     { 1, 0, 0, 1, 1 },
			                     { 0, 0, 0, 0, 0 },
			                     { 1, 0, 1, 0, 1 } };
 
     cout << "Max area of islands is: " << maxAreaOfIsland(grid);
     return 0;
}
