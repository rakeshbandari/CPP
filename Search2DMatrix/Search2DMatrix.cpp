/*

240. Search a 2D Matrix II

Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

*/
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n= matrix[0].size();
    
    int i=0;
    while(i < m)
	{
        if(matrix[i][0] == target) 
            return true;
        if(target > matrix[i][0])
            i++;
        if(target < matrix[i][0]){
    
	    	break;
		}    
    }
    
	cout << i << endl;
    
	int j=0;
    while(j<n)
	{
        if(target == matrix[i][j++])
            return true;
    }
    
    return false;
}

int main()
{
vector<vector<int>> matrix = {{2, 9, 12, 13, 16, 18, 18, 19, 20, 22},
							  {29, 59, 62, 66, 71, 75, 77, 79, 97, 99}};
  
    int target = 45;						            
	
	cout << searchMatrix(matrix, target);
	
	return 0;
}
