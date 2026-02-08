/*
Problem Description

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.

*/


#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
    int len = strs[0].size();
    string str = "";
    int start = 0;
    while(start < len)
    {
        char temp = strs[0][start];
        
        bool test = true;
        for(int i=1; i<strs.size(); i++)
        if(temp != strs[i][start])
		{
            test = false;
            break;    
        }
        
        if(test)
          str+=temp;
        else
          break;
        
        start++;
                    
    }
    return str;
}
 
int main()
{
	vector<string> str = {"flower","flow","flight"};
    string res = longestCommonPrefix(str);
    cout << res;
    return 0;
}
 
