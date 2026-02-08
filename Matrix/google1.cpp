#include <bits/stdc++.h>
using namespace std;

/*
remove islands with are not attached to the borders
1 = land;
0 = water 
input :
[
	[1, 0, 0, 0, 0, 0],
	[0, 1, 0, 1, 1, 1],
	[0, 0, 1, 0, 1, 0],
	[1, 1, 0, 0, 1, 0],   
	[1, 0, 1, 1, 0, 0],
	[1, 0, 0, 0, 0, 1],
]

output : 
[
	[1, 0, 0, 0, 0, 0],
	[0, 0, 0, 1, 1, 1],
	[0, 0, 0, 0, 1, 0],
	[1, 1, 0, 0, 1, 0],   
	[1, 0, 0, 0, 0, 0],
	[1, 0, 0, 0, 0, 1],
]
*/


void calling(vector<vector<int>> &grid, int i, int j)
{
    if(i<0 || j<0 || i >= grid.size() || j >= grid[0].size())
    {
        return;
    }   
    if(grid[i][j] == 1){
	    grid[i][j]=2;
	    calling(grid, i-1, j);
	    calling(grid, i, j+1);
	    calling(grid, i+1, j);
	    calling(grid, i, j-1); 
	}
}


void display(vector<vector<int>>& grid){
	
	int m = grid.size();
	int n = grid[0].size();
	cout << endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}
int main(){
	
	vector<vector<int>> grid = {
				{1, 0, 0, 0, 0, 0},
				{0, 1, 0, 1, 1, 1},
				{0, 0, 1, 0, 1, 0},
				{1, 1, 0, 0, 1, 0},
				{1, 0, 1, 1, 0, 0},
				{1, 0, 0, 0, 0, 1}};
				
	display(grid);
	
	int m = grid.size();
	int n = grid[0].size();
	
	
	for(int i=0;i<n;i++)
	{
		if(grid[0][i] == 1)
		calling(grid,0,i);
				
		if(grid[i][0] == 1)
		calling(grid,i,0);		
		
		if(grid[n-1-i][n-1] == 1)
		calling(grid, n-1-i, n-1);
		
		if(grid[n-1][n-1-i] == 1)
		calling(grid, n-1, n-1-i);
    } 
	
	
	for(int i=0; i<m; i++)
	for(int j=0; j<n; j++){
		if(grid[i][j] == 1)
		grid[i][j] = 0;
		if(grid[i][j] == 2)
		grid[i][j] = 1;
	}
	
	display(grid);	
			  
	return 0;
}
