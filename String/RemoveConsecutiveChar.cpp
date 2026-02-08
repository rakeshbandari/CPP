/*
Problem Description

Given a string A and integer B, remove all consecutive same characters that have length exactly B.

Problem Constraints
1 <= |A| <= 100000
1 <= B <= |A|

Input Format
First Argument is string A.
Second argument is integer B.

Output Format
Return a string after doing the removals.

Example Input
Input:
A = "aabcd"
B = 2

Output: "bcd"

Input:
A = "aabbccd"
B = 2
Output 2: "d"

*/


#include <bits/stdc++.h>
using namespace std;

string solve(string A, int B) {

    string str="";
    int len = A.length();
    
    int i=0;
    while(i < len)
	{
    	if(A[i] == A[i+1])
		{
			int start = i;
			int end = i+B-1;
    		while(start < end)
			{
    			if(A[start] == A[end])
				 start++;				
				else
				 break;	
			}
			if(start == end){
				i = end;
			}	
		}
		else
		{
			str+=A[i];	
		}
		i++;	
	}
    
    return str;
}
 
int main()
{
	string st = "aabcd";
    string res = solve(st,2);
    cout << res;
    return 0;
}
 
