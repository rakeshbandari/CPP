/*
Given a string s, return the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1

*/

#include <climits>
#include <iostream>
using namespace std;

int firstUniqChar(string s) {
    int len = s.length();
    int hash[26]={0};
    
    for(int i=0;i<len; i++)
        hash[s[i]-'a']++;
    
    for(int i=0;i<len; i++)
        if(hash[s[i]-'a'] == 1)
            return i;
    return -1;
}
int main()
{
    string s = "loveleetcode";    
    cout << firstUniqChar(s);
    return 0;
}
