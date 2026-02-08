/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Input: n = 1
Output: [["Q"]]
*/


#include <bits/stdc++.h>
using namespace std;
#define N 5
 
void printSolution(vector<vector<int>> &board)
{
	cout << endl << endl;
	int len = board.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}
  
bool isSafe(vector<vector<int>> &board, int row, int col)
{
    int i, j;
  
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
  
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
  
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
  
    return true;
}
  
bool solveNQUtil(vector<vector<int>> &board, int col)
{
    if (col >= N)
        return true;
  
    for (int i = 0; i < N; i++) {

        if (isSafe(board, i, col)) {

            board[i][col] = 1;
 		
            if (solveNQUtil(board, col + 1))
                return true;
  
            board[i][col] = 0;
        }
    }
    return false;
}
 
void invert(vector<vector<int>> &board){
        
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(board[i][j] == 1)
			{				
		     	board[i][j] = 0;
		    	board[i][N-1-j] = 1;
		    	break;
		    }
		}	    	
	}    
}
  
bool solveNQ()
{
    vector<vector<int>> board (N, vector<int> (N, 0)) ;
  
    if (solveNQUtil(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }
  
    printSolution(board);
    
	invert(board);
	
    printSolution(board);
    
	return true;
}
  
int main()
{
    solveNQ();
    return 0;
}
