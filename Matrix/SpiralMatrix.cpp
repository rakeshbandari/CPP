#include <iostream>
using namespace std;
 
#define R 4
#define C 4
 
void print_with_Recursion(int arr[R][C], int i, int j, int m, int n)
{
    if (i >= m or j >= n)
        return;
 
    for (int p = j; p < n; p++)
        cout << arr[i][p] << " ";
 
    for (int p = i + 1; p < m; p++)
        cout << arr[p][n - 1] << " ";
 
    if ((m - 1) != i)
        for (int p = n - 2; p >= j; p--)
            cout << arr[m - 1][p] << " ";
 
    if ((n - 1) != j)
        for (int p = m - 2; p > i; p--)
            cout << arr[p][j] << " ";
			
    print_with_Recursion(arr, i + 1, j + 1, m - 1, n - 1);
}


void print_Without_Recursion(int arr[R][C], int x1, int y1, int x2, int y2)
{	
	int i;
	
	int top = x1;
	int down = x2-1;
	int left = y1;
	int right = y2-1;
		
    while(top <= down && left <= right)
	{
		for(i=left; i<=right ;i++)
			cout << arr[top][i] << " ";
			top++;

		for(i=top; i<=down ;i++)
			cout << arr[i][right] << " ";
			right--;

		for(i=right; i>=left ;i--)
			cout << arr[down][i] << " ";
			down--;

		for(i=down; i>=top; i--)
			cout << arr[i][left] << " ";
			left++;			
	}
}

int main()
{
     int a[R][C] = { { 1, 2, 3, 4 },
                    { 5, 6, 7, 8 },
                    { 9, 10, 11, 12 },
                    { 13, 14, 15, 16 } };
     print_with_Recursion(a, 0, 0, R, C);
    return 0;
}
