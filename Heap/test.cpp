#include <bits/stdc++.h>
using namespace std;

vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    
    int sum = 0, idx = 0, val = 0;
    
    int tempSum = 0;
    
    vector<int> result;
    
    for(int i=0; i<nums.size(); i++)
    if(nums[i]%2 == 0)
    sum += nums[i];
    
    tempSum = sum;

    for(int i=0; i<queries.size(); i++)
    {
        
        idx = queries[i][1];
        val = nums[idx] + queries[i][0];
        
		if(nums[idx]%2 == 0)
		{
			tempSum-=nums[idx];
			nums[idx] = val;
			
			if(val%2 == 0)
			tempSum += val;				
		}
		else
		{
			nums[idx] = val;
			
			if(val%2 == 0)
			tempSum += val;				
		}	
        
        result.push_back(tempSum);    
    }
    
    return result;
}

int main()
{
	vector<int> nums = {1,2,3,4};
	
	vector<vector<int>> queries = {{1,0},{-3,1},{-4,0},{2,3}};
	
	
	vector<int> result = sumEvenAfterQueries(nums, queries);
	
	for(int d : result)
		cout << d << " ";
    
	return 0;
}
 


