/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

#include <bits/stdc++.h>
using namespace std;

char mp[256]={0};
int lengthOfLongestSubstring(string s) 
{
    int left=0;
    int right=0;    
    int global=0;
        
	while(right < s.length())
	{
		if(mp[s[right]] != 1)
		{
			mp[s[right]] = 1;
			global = max(global, right - left + 1);
			right++;
		}
		else
		{
			while(left != right)
			mp[s[left++]] = 0;			
		}		
	}
	global = max(global, right - left + 1);
    return global;    
}

int main()
{
    char str[] = "abcabcbb";
    	
	cout << "\nLength is: "
         << lengthOfLongestSubstring(str)
         << endl;
   
    return 0;
}
 
