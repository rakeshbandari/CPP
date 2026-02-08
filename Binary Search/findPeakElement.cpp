/*
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You must write an algorithm that runs in O(log n) time.

Constraints:

1 <= nums.length <= 1000

-231 <= nums[i] <= 231 - 1

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

*/
#include <bits/stdc++.h>
using namespace std;


int findPeakElement(vector<int>& nums) 
{              
    int l = 0, r = nums.size() - 1;
    while (l < r) 
    {
        int mid = (l + r) / 2;
        
        if (nums[mid] > nums[mid + 1])
            r = mid;
        else
            l = mid + 1;
    }
    return nums[l];        
}

int main()
{
	//vector<int> nums = {1, 2, 3, 1};	
	vector<int> nums = {1,2,1,3,5,6,7};
	
	cout << findPeakElement(nums);  
    return 0;
}
 


