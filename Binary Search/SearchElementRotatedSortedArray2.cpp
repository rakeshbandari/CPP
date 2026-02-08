// Search an element in sorted and rotated
// array using single pass of Binary Search
#include <bits/stdc++.h>
using namespace std;



bool binarySearch(vector<int>& nums, int start, int end, int target) 
{
    if (start > end) return false;
    
	int mid = (start + end) / 2;
    
	if (target == nums[start] || target == nums[end] || target == nums[mid]) 
		return true;
    
	if (mid == start) 
		return false;
		
    if (nums[mid] > nums[start]) 
	{
        if (target < nums[mid] && target > nums[start]) {
            return binarySearch(nums, start, mid, target);
        }
    }
    else if (nums[mid] < nums[end]) {
        if (target < nums[end] && target > nums[mid]) {
            return binarySearch(nums, mid, end, target);
        }
    }
    return binarySearch(nums, start+1, end-1, target);
}
    

int main()
{
    vector<int> arr = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    
    int key = 2;
 
	if(binarySearch(arr, 0, arr.size()-1, key))
	 cout << "True";
	else
	 cout << "False"; 
	  
    return 0;
}
 


