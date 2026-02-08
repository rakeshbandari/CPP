/*
41. First Missing Positive

Given an unsorted integer array nums, find the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
 
*/
#include <bits/stdc++.h>
using namespace std;

void display(vector<int>& nums)
{
	cout << endl << endl;
	for(int c: nums)
	 cout << c << " ";
}
int firstMissingPositive(vector<int>& nums) {
    
    if(nums.size()==1 && nums[0]<=0)
        return 1;
    display(nums);    
    for(int i=0;i<nums.size();i++)
	{
        if(nums[i]<=0 || nums[i] > nums.size()+1)
            nums[i]=nums.size()+1;            
    }
    display(nums);
    for(int i=0;i<nums.size();i++)
	{
        if(abs(nums[i]) > nums.size())
			continue;
        
		int idx = abs(nums[i])-1;
        
        if( nums[idx] > 0)
            nums[idx] = -nums[idx];
    }
    display(nums);
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0)
            return i+1;
    }
    display(nums);
    return nums.size()+1;
}

int main()
{
    vector<int> arr = {3,4,-2,1};
    
    cout << "\n\nResult : " << firstMissingPositive(arr);	
	  
    return 0;
}
 


