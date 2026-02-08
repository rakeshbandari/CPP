/*
Given a 2D grid consists of 0s (land) and 1s (water).  
An island is a maximal 4-directionally connected group of 0s and a closed island is an island 
totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

*/
// C++ Program to count islands in boolean 2D matrix
#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>>& grid){
	int r = grid.size();
    int c = grid[0].size();
    cout << endl;
    cout << endl;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
} 

bool isClosed(vector<vector<int>>& grid, int i, int j) {
	
	if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()){
	return false;
	}

    if(grid[i][j] == 1){
        return true;
    }
    
    /* DFS will not run on all the connected cells if we try to return isClosed(i-1,j,grid) && isClosed(i+1,j,grid) && isClosed(i,j-1,grid) && isClosed(i,j+1,grid) 
	as all the functions may not be called depending upon if we get a false at the beginning itself.running all the dfs functions are necessary so that an island is not visited again.*/
    
  //  cout << "\ni : "<<i<<"  j : "<<j; 
  //  display(grid);
    
  //  getchar();
    
    grid[i][j] = 1;
    
    bool ans1,ans2,ans3,ans4;
    
    ans1 = ans2 = ans3 = ans4 = false;
    
    ans1 = isClosed(grid, i-1, j);
    ans2 = isClosed(grid, i+1, j); 
    ans3 = isClosed(grid, i, j-1);
    ans4 = isClosed(grid, i, j+1);
    
    return ans1 && ans2 && ans3 && ans4;
}
    
    
int closedIsland(vector<vector<int>>& grid) {
    int r = grid.size();
    int c = grid[0].size();
    int closed = 0;
    
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(grid[i][j] == 0){            	
                if(isClosed(grid, i, j)){
                	closed++;
                	display(grid);
				}                
            }
        }
    }
    
    return closed;
}

int main()
{
    vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},
								{1,0,0,0,0,1,1,0},
								{1,0,1,0,1,1,1,0},
								{1,0,0,0,0,1,0,1},
								{1,1,1,1,1,1,1,0}};
 
     cout << "Number of islands is: " << closedIsland(grid);
     return 0;
}
