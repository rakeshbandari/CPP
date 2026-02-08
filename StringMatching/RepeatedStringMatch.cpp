/*
686. Repeated String Match

Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b?????? to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "",  repeated 1 time is "abc" and repeated 2 times is "abcabc".

 

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
Example 2:

Input: a = "a", b = "aa"
Output: 2
Example 3:

Input: a = "a", b = "a"
Output: 1
Example 4:

Input: a = "abc", b = "wxyz"
Output: -1

*/
#include<bits/stdc++.h>
using namespace std;


int repeatedStringMatch(string a, string b) {
    int hashA[26] = {0};
	int hashB[26] = {0};
    
	for(int i=0; i < a.length(); i++)
        hashA[a[i]-'a'];
    
    for(int i=0; i < b.length(); i++)
        hashB[b[i]-'a'];
    
    for(int i=0; i<26; i++)
        if(hashB[i] > 0 && hashA[i] == 0)
            return -1;
    
    string text = a + a;
    int i=2;
    while(1)
    {     
        if(text.length() > b.length())
        {
            int found = text.find(b);
            if(found != string::npos)
                return i;
			else
				return -1;	                
        }
        text = text + a;
        i++;
    }    
    return -1;
}

int repeatedStringMatch2(string a, string b) {
        
    string temp="";
    int count = 0;
    
    while(temp.size() < b.size()) 
	{
        temp = temp + a;
        count++;
    }
    
    
    if(temp.find(b) != string::npos) {
        return count;
    }
    else {
        temp = temp + a;
        count++;
        if(temp.find(b) != string::npos) {
            return count;
        }
    }
    
    return -1;
}

int main()
{
	string a = "abcd";
	string b = "cdabcdab";
	
	cout << endl;
	cout << (repeatedStringMatch2(a,b));
	
	return 0;
}
