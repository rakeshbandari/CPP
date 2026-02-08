/*
https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/

Rotate a matrix by 90 degree in clockwise direction without using any extra space

Input
1  2  3  4
5  6  7  8
9 10 11 12
13 14 15 16
           
Output
13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4 

*/
#include <bits/stdc++.h>
using namespace std;
 
void rotate90Clockwise(vector<vector<int>> a)
{
	int N = a.size();
	
    for (int i = 0; i < N / 2; i++) 
	{
        for (int j = i; j < N - i - 1; j++) 
		{
            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}
 
void printMatrix(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}
 
int main()
{
    vector<vector<int>> arr = { { 1, 2, 3, 4 },
                      			{ 5, 6, 7, 8 },
                      			{ 9, 10, 11, 12 },
                      			{ 13, 14, 15, 16 } };
    rotate90Clockwise(arr);
    printMatrix(arr);
    return 0;
}
