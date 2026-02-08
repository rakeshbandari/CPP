/*
154. Find Minimum in Rotated Sorted Array II

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.


Example 1:

Input: nums = [1,3,5]
Output: 1
Example 2:

Input: nums = [2,2,2,0,1]
Output: 0

*/
#include <bits/stdc++.h>
using namespace std;

int findMin1(vector<int>& nums, int l, int r) 
{
    if(l == r || nums[l] < nums[r])
        return nums[l];
    
    if(l + 1 == r)
        return min(nums[l], nums[r]);
    
    int mid = (l + r) >> 1;
    
    if(nums[mid] < nums[l])
        return findMin1(nums, l, mid);
    
    else if(nums[mid] > nums[l])
        return findMin1(nums, mid, r);
    
    return min(findMin1(nums, l, mid), findMin1(nums, mid, r));
}

int findMin(vector<int>& nums) 
{
    return findMin1(nums, 0, nums.size() - 1);
}

int main()
{
	vector<int> arr = {2,2,2,0,1};
	
	cout << findMin(arr);
	
	return 0;
}
