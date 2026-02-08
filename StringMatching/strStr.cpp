/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Example 3:
Input: haystack = "", needle = ""
Output: 0

*/
#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) 
{
    if(needle.size()==0) 
		return 0;
		
    int idx=0;
    
    for(int i=0; i < haystack.size(); i++)
	{
        if(haystack[i] == needle[idx])
		{
           idx++;
        }
        else 
		{
           i = i - idx;
           idx = 0;
        }
        
        if(idx == needle.size()) 
			return i - idx + 1;
    }
    return -1;
}

int main()
{
	string str = "hello";
	string s = "ll";
	
	cout << strStr(str, s);
		
	return 0;
}
