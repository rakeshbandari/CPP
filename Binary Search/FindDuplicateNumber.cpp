/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [1,1]
Output: 1
Example 4:

Input: nums = [1,1,2]
Output: 1

*/
#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) 
{
    int size = nums.size();
    
    int x;
    for(int i=0; i<size; i++)
    {
        if(nums[abs(nums[i])] > 0)
            nums[abs(nums[i])] = -nums[abs(nums[i])];
        else
        {
            x = abs(nums[i]);
            break;
        }
    }
    return x;
}

int main()
{
    vector<int> arr = {1, 3, 4, 2, 2};
    
    cout << findDuplicate(arr);	
	  
    return 0;
}
 


