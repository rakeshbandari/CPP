/*

*/
#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &A, int low, int high)
{
    if(low > high)
        return -1;

    int mid = (low + high)/2;    

    if(A[mid-1] < A[mid] && A[mid] > A[mid + 1])
        return mid;
 
    if(A[low] > A[mid])
        return findPivot(A, low, mid-1);
    
    return findPivot(A, mid+1, high);    
}

int solve(vector<int> &A, int B) 
{
    int pivot = findPivot(A, 0, A.size()-1);
    
    cout << "Pivot : " << pivot << " : "<< A[pivot] << endl;
    
    if(A[pivot] == B)
        return pivot;
       
      
    int start=0, end = pivot;
    
    while(start <= end)
    {
        int mid = (start+end)/2;
		cout << A[mid] << endl;
        if(B == A[mid])
        {
            return mid;
        }

        if(B > A[mid])
            start = mid+1;
        else
            end = mid-1;    
    }


    start = pivot+1, end = A.size()-1;
    
    while(start <= end)
    {
        int mid = (start+end)/2;
		cout << A[mid] << endl;
        if(B == A[mid])
        {
            return mid;
        }

        if(A[mid] > B)
            start = mid+1;
        else
            end = mid;    
    }

    return -1;
}

int main()
{
    //vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11 };
    
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21};
		
    int key = 1;
 		
    cout << solve(arr, key) << endl;
    return 0;
}
 


