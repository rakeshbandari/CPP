#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
 
void display(vector< vector<int> > arr) {
	for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }   
        cout << endl;
    }
} 
void print(vector< vector<int> > &arr, int i, int j, int m, int n, int &count)
{
    if (i >= m or j >= n)
        return;
    
    for (int p = j; p < n; p++)
        arr[i][p] = count++;

    for (int p = i + 1; p < m; p++)
        arr[p][n - 1] = count++;

    if ((m - 1) != i)
        for (int p = n - 2; p >= j; p--)
            arr[m - 1][p] = count++;

    if ((n - 1) != j)
        for (int p = m - 2; p > i; p--)                
            arr[p][j] = count++;

    print(arr, i + 1, j + 1, m - 1, n - 1, count);
}

vector< vector<int> > generateMatrix(int n) {
    vector< vector<int> > arr(n, vector<int> (n, 0));        
    
	int count = 1;    
    print(arr, 0, 0, n, n, count);
    
    display(arr);
           
    return arr;        
}


int main()
{
	int n = 3;
	
	vector< vector<int> > vec = generateMatrix(3);
    
    
	 
    return 0;
}
