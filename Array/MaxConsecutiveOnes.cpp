/*
Max Consecutive Ones

solution is using Sliding Window Concept
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> nums = {1,1,0,1,1,1};
			
	int left=-1, right=0, sum=0, ans = INT_MIN;
	
	for(int right=0; right < nums.size(); right++)
	{
		if(nums[right] == 0)
		{
			cout << endl << right << "  " << left << endl;
			ans = max(ans, right - left);
			
			//while(nums[right] == 0 ) right++;
			left = right;
		}
	}
	cout << endl << right << "  " << left << endl;
	ans = max(ans, right - left);
	
	cout << ans;
	
	return 0;
}

