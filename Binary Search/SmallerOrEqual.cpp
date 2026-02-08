/*
Problem Description

Given an sorted array A of size N. Find number of elements which are less than or equal to B.
NOTE: Expected Time Complexity O(log N)

Problem Constraints
1 <= N <= 106
1 <= A[i], B <= 109

Input Format
First agument is an integer array A of size N.
Second argument is an integer B.

Output Format
Return an integer denoting the number of elements which are less than or equal to B.

Example Input
Input 1:
 A = [1, 3, 4, 4, 6]
 B = 4
Output 1: 4

Input 2:
 A = [1, 2, 5, 5]
 B = 3
Output 2: 2
 
*/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) 
{  
	int start = 0, end = A.size()-1;	
	int pvt=0;
	
	if(B < A[0])
		return 0;
		
	if(B > A[end])
		return end+1;
			
    while(start < end)
    {
    	int mid = (start + end)/2;  	
   	
    	if(A[mid] == B || (A[mid-1] < B && B < A[mid+1])) 
    	{
    		cout << A[mid-1] << " ccc " << A[mid+1] << endl;
    		pvt = mid;
    		break;
		}
		
		if(A[start] == B){
			pvt = start;
			break;
		}
		if(A[end] == B){
			pvt = end;
			break;
		}		
		
		if(B < A[mid])
			end = mid - 1;			
		else
			start = mid + 1;	
	}
	
	while(A[pvt] == A[pvt + 1])
	pvt++;
	
	while(A[pvt] > B)
	pvt--;

		    
	cout << A[pvt] << endl;    
    return (pvt);    
}

int main()
{
   
	vector<int> arr = {4, 4, 12, 12, 15, 19, 23, 24, 34, 42};
		
    int key = 48;
 		
    cout << solve(arr, key) << endl;
        
    return 0;
}
 


