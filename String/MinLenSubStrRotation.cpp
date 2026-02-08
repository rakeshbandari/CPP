/*
Minimum length of substring whose rotation generates a palindromic substring

Input: str = “abcbd” 
Output: 0 
Explanation: No palindromic substring can be generated. There is no repeated character in the string.
 

Input: str = “abcdeba” 
Output: 3 
Explanation: Rotate substring “deb” to convert the given string to abcbeda with a palindromic substring “bcb”. 

*/
#include <bits/stdc++.h>
using namespace std;
 
int count_min_length(string s)
{
 
    int hash[26];
 
    int ans = INT_MAX;
 
    for (int i = 0; i < 26; i++)
        hash[i] = -1;
 
    for (int i = 0; i < s.size(); i++) { 
        if (hash[s[i] - 'a'] == -1)
            hash[s[i] - 'a'] = i;
        else {
            if (hash[s[i] - 'a'] == i - 1 || hash[s[i] - 'a'] == i - 2)
                return 0;
 
            ans = min(ans,  i - hash[s[i] - 'a'] - 1);
 
            hash[s[i] - 'a'] = i;
        }
    }
     
    if (ans == INT_MAX)
        return -1;
 
    return ans;
}
int main()
{
    string str = "abcdeba";
    cout << count_min_length(str);
}
