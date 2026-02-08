/*
153. Find Minimum in Rotated Sorted Array

Given the sorted rotated array nums of unique elements, return the minimum element of this array.
Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 

*/
#include <bits/stdc++.h>
using namespace std;

int finPivot(vector<int>& nums, int low, int high)
{         
    if(low > high) return -1;
    
    if(low == high) return low;
    
    int mid = (low + high)/2;
    
    if(mid < high && nums[mid] > nums[mid+1])
        return mid;
    
    if(low < mid && nums[mid-1] > nums[mid])
        return mid-1;
    
    if(nums[low] < nums[mid])
        return finPivot(nums, mid+1, high);
    return finPivot(nums, low, mid-1);        
}


int findMin(vector<int>& nums) 
{
    if(nums.size() == 1) return nums[0];
    int pivot = finPivot(nums, 0, nums.size()-1);
    
    if(pivot == nums.size()-1)
    return nums[0]; 
    
    return min(nums[0],nums[pivot+1]);
}


int main()
{
	vector<int> arr = {3,4,5,1,2};
	
	cout << findMin(arr);
	
	return 0;
}
