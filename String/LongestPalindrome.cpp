/*
409. Longest Palindrome  Leet Code

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Input: s = "abccccdd"
Output: 7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/

#include <bits/stdc++.h>
using namespace std;
 
int longestPalindrome(string str) {
        
    int maxLength = 0;
    int singles = 0; 

    int hash[256]={0};
    int len = str.length(); 

    for (int i = 0; i < len; ++i) {
        hash[str[i]]++;
    }
        
    for(int i = 0; i<256; i++)
        if(hash[i] > 0){
            
            if(hash[i] == 1){
                singles++;
                continue;
            }
            
            if(hash[i]%2 == 0){
                maxLength = maxLength + hash[i];
            }                    
            else{
                maxLength = maxLength + hash[i] - 1;
                singles++;
            }
        }
    if(singles)
        maxLength++;
    
    return maxLength;
}
 
int main()
{
    string str = "abccccdd";
    cout << "\nLength is: "
         << longestPalindrome(str)
         << endl;
    return 0;
}
 
