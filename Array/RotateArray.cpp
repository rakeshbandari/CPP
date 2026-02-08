/*
https://leetcode.com/problems/rotate-array/

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

*/
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) 
{
    int len = nums.size();

    for(int i=0; i < k; i++)
    {
        int x = nums[len-1];
        int j = len-1;
        while(j > 0)
        {
            nums[j] = nums[j-1];
            j--;	
        }
        nums[0] = x;
    }	
}


void rotate2(vector<int>& nums, int k) 
{
    int len = nums.size();
	
	vector<int> vec;
	
	for(int i=len-k; i < len; i++)
		vec.push_back(nums[i]);
		
	for(int i=len-1; i >= len-k-1; i--)
	{
		nums[i] = nums[i-k];
	}
    for(int i=0; i < vec.size(); i++)
    {
		nums[i] = vec[i];
    }	
}

void rotate3(vector<int>& nums, int k) 
{
	vector<int> arr;
    k %= nums.size();
  
    for (int i=nums.size()-k; i<nums.size(); i++){
        arr.push_back( nums[i]);
    }
    for (int i= nums.size()-1; i>=k; i--){
        nums[i] = nums[i-k];
    }
    for (int i =0 ; i< k; i++){
        nums[i] = arr[i];
    }
}


int main()
{
	
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7};
	
	rotate3(arr, 3);
	
	cout << endl;
	for(int i : arr)
		cout << i << " ";
		   
    return 0;
}

