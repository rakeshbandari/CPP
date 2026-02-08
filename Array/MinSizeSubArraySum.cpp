/*
Minimum Size Subarray Sum

solution is using Sliding Window Concept

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> nums = {2, 3, 1, 2, 4, 3};
	int target = 7;
	
	int left=0, sum=0, ans = INT_MAX;
	
	for(int right=0; right < nums.size(); right++)
	{
		sum += nums[right];	
		while(sum >= target)
		{
			ans = min(ans, right+1-left);
			
			sum -= nums[left++];	
		}		
	}
	
	cout << ans;
	
	return 0;
}

