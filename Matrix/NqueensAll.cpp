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
 
void printSolution(vector<vector<string>> &result)
{
	cout << endl << endl;
	for(int i=0; i < result.size(); i++){
    	for(int j=0; j < result[0].size(); j++){
    		cout << result[i][j] << " ";
		}
		cout << endl;
	}	
}
  
vector<vector<string>> result;
bool isValid(vector<string>& temp,int row, int column,int n){

    for(int i = 0; i < n; i++){
        if(temp[i][column] == 'Q'){
            if(i != row){
                return false;
            }
        }
    }
    for(int i = row,j = column; i >= 0 && j >= 0; j--,i--){
        if(temp[i][j] == 'Q'){
            if(i != row || j != column){
                return false;
            }
        }
    }
    for(int i = row,j = column; i >= 0 && j<n; j++,i--){
        if(temp[i][j] == 'Q'){
            if(i != row || j != column){
                return false;
            }
        }
    }
    return true;
}
void helper(vector<string>& temp,int row,int n){
    if(row == n){
        result.push_back(temp);
        return;
    }
    for(int i = 0 ; i < n; i++){
        if(isValid(temp,row,i,n)){
            temp[row][i] = 'Q';
            helper(temp,row+1,n);
            temp[row][i] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<string >temp;
    for(int i = 0; i < n; i++){
        string s ="";
        for(int j = 0; j < n; j++){
            s += ".";
        }
        temp.push_back(s);
    }
    helper(temp,0,n);
    return result;
}
  
int main()
{
	result = solveNQueens(4);
    
	printSolution(result);
    
    return 0;
}
