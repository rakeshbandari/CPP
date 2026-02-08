/*
https://www.interviewbit.com/problems/matrix-median/
*/
#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int> > &A) 
{
	int n = A.size();	
	int m = A[0].size();
	
	int low = INT_MAX;
		
	for(int i=0;i<n;i++)
		low = min(low,A[i][0]);
	
	int high = INT_MIN;
	
	for(int i=0;i<n;i++)
		high = max(high,A[i][m-1]);		
	
	int median = (n*m+1)/2;
	
	cout << "low : " << low << "  High : "<<high << "  Median : " << median << endl;
	
	while(low < high)	
	{
	
		int mid = (low + high)/2;
		
		int place = (long long)0;
		
		for(int i=0; i < n; i++)
		{
			place += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
		}
	
		cout << "low : " << low << "  High : " << high << "  Median : " << place << endl;	
		
		if(place < median)		
		low = mid+1;		
		else		
		high = mid;
		
	}
	
	return low;   
}


int medianRowwiseSortedMatrix(vector<vector<int> > &A)
{
	int M = A.size(); 
	int N = A[0].size();
	
    int desired_count = (1+(M*N)/2);
	    
    cout << desired_count << endl;
 
    int min = A[0][0];
    int max = A[M-1][N-1];
	
	int counter =0;
    
	while(min < max)
    {
        counter=0;
        int mid = (min + max)/2;
        for(int i= 0; i < M; i++)
        {
            int temp = upper_bound(A[i].begin(), A[i].end(), mid) -  A[i].begin();
			counter += temp;
			
			cout << A[i][0] << " , "<< A[i][N-1] << " : "<< mid << " == "<< temp<< endl;
						
			//counter += upper_bound(A[i].begin(), A[i].end(), mid) -  A[i].begin();
        }
        if(counter < desired_count)
            min = mid+1;
        else
            max = mid;
    }
    return min;
}

int main()
{

	vector<vector<int>> A = {{1, 3, 5},
         		 	 		 {2, 6, 9},
         			 		 {3, 6, 9}};
         			
	cout << findMedian(A);
		
	return 0;
}
