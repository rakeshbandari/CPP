/*
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
You may assume the input array always has a valid answer.

Example 1:

Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.
Example 2:

Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]

*/
#include<bits/stdc++.h>
using namespace std;



void wiggleSort(vector<int> &nums)
{
    vector<int> a = nums;
    
    sort(a.begin(), a.end());
	
	for(int c:a)
	cout << c << " ";
	    
    int n = nums.size();
    
    int mid;
    
    if (n % 2 == 0)
        mid = n / 2 - 1;
    else
        mid = n / 2;

    int index = 0;
    while (index<nums.size())
    {
        if (index % 2 == 0)
        {
            nums[index] = a[mid];
            index++;
            mid--;
        }
        else
        {
            nums[index] = a[n - 1];
            index++;
            n--;
        }
    }
}

int main()
{
	vector<int> nums = {1,3,2,2,3,1};
	wiggleSort(nums);
	
	cout << endl;
	for(int c:nums)
	cout << c << " ";
	
	return 0;
}
