/*
https://www.interviewbit.com/problems/search-for-a-range/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(const vector<int> &A, int B) 
{
    vector<int> vec;
    int low = 0, high = A.size()-1;

    if(low == high && A[low] == B)
    {
        vec.push_back(0);
        vec.push_back(0);
        return vec;
    }   

    int idx = -1;
    while(low <= high)
    {
        int mid = (low+high)/2;

        if(B == A[mid]){
            idx = mid;
            break;
        }

        if(B < A[mid])
            high = mid-1;
        else
            low = mid+1;    
    }
    
    if(idx != -1)
    {
        int i=idx, j=idx;
        
        while(i >= 0 &&A[i] == B)
        i--;
        
        while(j < A.size() && A[j] == B)
        j++;

        vec.push_back(i+1);
        vec.push_back(j-1);

    }
    else{
        vec.push_back(-1);
        vec.push_back(-1);
    }
    return vec;
}

int main()
{
	vector<int> matrix = {1, 2, 6, 9, 9};
  
    int target = 2;						            
	
	vector<int> res = searchRange(matrix, target);
	
	cout << res[0] << ", " << res[1];
	
	return 0;
}
