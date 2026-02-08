/*

240. Search a 2D Matrix II

Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

*/
#include <bits/stdc++.h>
using namespace std;

int searchMatrix(vector<vector<int>>& A, int B) {

    int n = A.size();
    int m = A[0].size();
    int low = 0, high = m-1,i = 0;
    
    while(low <= high && i < n)
	{
        if(A[i][m-1]<B){i++;continue;}
        
        int mid = (low+high)/2;
        
        if(A[i][mid]==B)return 1;
        else if(A[i][mid]<B)low = mid+1;
        else high = mid - 1 ;
    }    
    return 0;
}

int main()
{
vector<vector<int>> matrix = {{2, 9, 12, 13, 16, 18, 18, 19, 20, 22},
							  {29, 59, 62, 66, 71, 75, 77, 79, 97, 99}};
  
    int target = 45;						            
	
	cout << searchMatrix(matrix, target);
	
	return 0;
}
