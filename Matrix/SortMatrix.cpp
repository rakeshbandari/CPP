// C++ implementation to sort
// the given matrix in strict order
#include <bits/stdc++.h>
using namespace std;
#define N 3
#define M 3


void printMat(int mat[N][M], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to sort the matrix
void sortMat(int data[N][M], int row, int col)
{
    // Number of elements in matrix
    int size = row * col;
 
    // Loop to sort the matrix
    // using Bubble Sort
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
 
            // Condition to check
            // if the Adjacent elements
            if (data[j / col][j % col] > data[(j + 1)/ col][(j + 1) % col])
            {
                 // Swap if previous value is greater
                int temp = data[j / col][j % col];
                data[j / col][j % col] = data[(j + 1)/ col][(j + 1) % col];
                data[(j + 1) / col][(j + 1) % col] = temp;
            }
        }
    }
}
 
int main()
{
    int mat[N][M] = { { 5, 4, 7 },
                      { 1, 3, 8 },
                      { 2, 9, 6 } };
         
    int row = N;
    int col = M;
 
    sortMat(mat, row, col);

    printMat(mat, row, col);

    return 0;
}
