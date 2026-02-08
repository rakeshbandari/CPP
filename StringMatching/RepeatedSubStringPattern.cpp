/*

Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

Example 1:
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

Example 2:
Input: s = "aba"
Output: false

Example 3:
Input: s = "abcabcabcabc"
Output: true

Explanation: It is the substring "abc" four times or the substring "abcabc" twice.

*/
#include<bits/stdc++.h>
using namespace std;

bool repeatedSubstringPattern(string s) 
{
	string text;
// the idea is to create a string by appennding the same string twice, then by deleting first and last character, we have to ceck whether original string is present int it or not.
    text = s + s;
	cout << text << endl;
    text= text.substr(1,2*(s.size()- 1));
	
	cout << text << endl;
    if(text.find(s) == string::npos)
    {
    	cout << (string::npos) << endl;
    	return false;
	}
        

    return true;
}

bool repeatedSubstringPattern2(string s) 
{
	string text = s + s;

    text = text.substr(1, 2*(s.size()- 1));
	
	int found = text.find(s);
	
	// npos is constant static value with the highest possible value for an element of type size_t.
    if(found != string::npos)
    {   		
    	return true;
	}     

    return false;
}

int main()
{
	string str = "ababz";
	
	cout << endl;
	cout << (repeatedSubstringPattern2(str) ? "True" : "False");
	
	str = "abab";
	cout << endl;
	cout << (repeatedSubstringPattern2(str) ? "True" : "False");
			
	return 0;
}
