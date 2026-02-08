
#include <bits/stdc++.h>
using namespace std;
#define N 4
 
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
  
/* A utility function to check if a queen can
   be placed on board[row][col]. Note that this
   function is called when "col" queens are
   already placed in columns from 0 to col -1.
   So we need to check only left side for
   attacking queens */
bool isSafe(vector<vector<int>> &board, int row, int col)
{
    int i, j;
  
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
  
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
  
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
  
    return true;
}
  
/* A recursive utility function to solve N
   Queen problem */
bool solveNQUtil(vector<vector<int>> &board, int col)
{
    if (col >= N)
        return true;
  
    for (int i = 0; i < N; i++) {

        if (isSafe(board, i, col)) {

            board[i][col] = 1;
 		//	printSolution(board);
 		//	getchar();
            if (solveNQUtil(board, col + 1))
                return true;
  
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}
  
bool solveNQ()
{
    vector<vector<int>> board = { { 0, 0, 0, 0 },
		                          { 0, 0, 0, 0 },
		                          { 0, 0, 0, 0 },
		                          { 0, 0, 0, 0 } };
  
    if (solveNQUtil(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }
  
    printSolution(board);
    return true;
}
  
int main()
{
    solveNQ();
    return 0;
}
