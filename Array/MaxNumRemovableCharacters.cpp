/*
Input: s = "abcacb", p = "ab", removable = [3,1,0]
Output: 2
Explanation: After removing the characters at indices 3 and 1, "abcacb" becomes "accb".
"ab" is a subsequence of "accb".

If we remove the characters at indices 3, 1, and 0, "abcacb" becomes "ccb", and "ab" is no longer a subsequence.
Hence, the maximum k is 2.

*/

#include <bits/stdc++.h>
using namespace std;
 

bool check(vector<int>&arr,int idx,string s,string p){
    vector<char> x;
    for(int i=0;i<s.size();i++){
        x.push_back(s[i]);
    }

    for(int i=0;i<=idx;i++){
        x[arr[i]]='#';
    }
    
    for(int i=0;i<s.size();i++)
    	cout << x[i];
    	cout << endl;
    	
    int i=0;
    int j=0;
    while(i<x.size() && j<p.size()){
        if(x[i]==p[j]){
            i++;
            j++;
        }
        else
            i++;
    }
    return j==p.size();
}

int maximumRemovals2(string s, string p, vector<int>&arr) {
    int start=0;
    int end=arr.size()-1;
    int ans=0;
    while(start<=end)
	{
        int mid=start+(end-start)/2;
        if(!check(arr,mid,s,p)){
            end=mid-1;
        }
        else{
            ans=max(ans,mid+1);
            start=mid+1;
        }
    }
    return ans;
}


int maximumRemovals(string s, string p, vector<int>& rem) {
    int l = 0, r = rem.size();
    vector<int> map(s.size(), INT_MAX);
    for (int i = 0; i < rem.size(); ++i)
         map[rem[i]] = i;
    while (l < r) {
        int m = (l + r + 1) / 2, j = 0;
        for (int i = 0; i < s.size() && j < p.size(); ++i)
            if (map[i] >= m && s[i] == p[j])
                ++j;
        if (j == p.size())
            l = m;
        else
            r = m - 1;
    }
    return l;
}

int main()
{
	int n;
	string s="abcacb";
	string p="ab";
	vector<int> v={3,1,0};
    cout << maximumRemovals(s,p,v); 
    return 0;
}
