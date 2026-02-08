/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.

Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]

*/
#include <bits/stdc++.h>
using namespace std;

multiset <double> arr;

void insert(double x)
{
  	arr.insert(x);
}
void remove(double x)
{
  	arr.erase(arr.find(x));
}

double getMedian()
{
	  int n = arr.size();
	  
	  double a = *next(arr.begin(), n/2 - 1);
	  double b = *next(arr.begin(), n/2);
	  
	  if(arr.size() & 1)
	  	return b;
	  return (a + b) / 2.0;
}

vector<double> medianSlidingWindow(vector<int>& nums, int k) 
{
	vector <double> ans;
	arr.clear();
	  
	for(int i = 0; i < k; i++)
	{	
	   insert(nums[i]);
	}
	  
	for(int i = k, j = 0; i <= nums.size(); i++, j++)
	{
	      if (i < nums.size())
	      {
	        ans.push_back(getMedian());
	        remove(nums[j]);
	        insert(nums[i]);
	      }
	      else
	        ans.push_back(getMedian());
	}
	  
	return ans;
}

int main()
{
	vector<int> nums = {1,2,3,4,2,3,1,4,2};
	int target = 3;
	
	vector<double> result = medianSlidingWindow(nums, target);
	
	for(double d : result)
		cout << d << " ";
    
	return 0;
}
 


