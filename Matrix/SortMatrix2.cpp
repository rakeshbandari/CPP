// C++ implementation to sort
// the given matrix in strict order
#include <bits/stdc++.h>
using namespace std;
#define N 3
#define M 3


void printMat(vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}


void sortMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int temp[n * n];
    int k = 0;
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[k++] = mat[i][j];
 
    sort(temp, temp + k);
     
    k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = temp[k++];
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void sortMat(vector<vector<int>> &mat)
{
    // Number of elements in matrix
    int row = mat.size();
    int col = mat[0].size();
    
    cout << endl << row << ", " << col << endl;
    int size = row * col;
 
    // Loop to sort the matrix
    // using Bubble Sort
    
	  bool swapped = false;
	  do 
	  {     
        swapped = false;
        for (int i = 0; i < size - 1; i++) 
        {
        	int a = i/col;
			int b = i%col; 			
			
			int c = (i+1)/col;
			int d = (i+1)%col;
			
			cout << mat[a][b] << " " << mat[c][d] << endl;
            if (mat[a][b] > mat[c][d])
            {
                swap(&mat[a][b], &mat[c][d]);
                swapped = true;
		    }              
        }           
	  }while(swapped);
}
 
int main()
{
    vector<vector<int>> mat = { { 5, 4, 7 },
                      			{ 1, 3, 8 },
                      			{ 2, 9, 6 } };
         
  //sortMatrix(mat); // Not an Optimal Solution
    sortMat(mat); //optimal solution

    printMat(mat);

    return 0;
}
