/*
https://www.interviewbit.com/problems/matrix-median/
*/
#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int> > &A) 
{
    int m = A.size();
    int n = A[0].size();
    
    int minm = A[0][0];
    int maxm = A[m-1][n-1];

    int req = (m*n+1)/2;
    while(minm < maxm)
    {
        int mid = (minm + maxm)/2;

        int place = 0;

        for(int i=0; i < m; i++)
        {
        	place += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();	
        	cout << place << " ";
		}
		
	
        if(place < req)
            minm = mid+1;
        else
            maxm = mid;    
    }
    return minm;    
}

int main()
{

	vector<vector<int>> A = {{1, 3, 5},
         		 	 		 {2, 6, 9},
         			 		 {3, 6, 9}};
         			
	cout << findMedian(A);
		
	return 0;
}
