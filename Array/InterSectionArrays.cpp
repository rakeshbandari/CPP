// https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int hash[1001]={0};
    
    vector<int> ans;
    
    for(int i=0;i<nums1.size();i++){
        hash[nums1[i]]++;
    }
    
    for(int i=0;i<nums2.size();i++)
    {
        if(hash[nums2[i]])
        {
            ans.push_back(nums2[i]);
            hash[nums2[i]]=0;
        }
    }
    return ans;
}

int main()
{
    vector<int> a = { 1, 2, 5, 6, 2, 3, 5, 7, 3 };
    vector<int> b = { 2, 4, 5, 6, 8, 9, 4, 6, 5, 4 };
 
    vector<int> res = intersection(a, b);
    
    for(int a : res)
    	cout << a << " ";
    
    return 0;
}

