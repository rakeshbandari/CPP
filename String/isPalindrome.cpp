#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string s) 
{    
    int len = s.length();    
    int start=0;
    for(int i=0; i < len; i++)
	{
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) 
		{
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[start++] = s[i]+32;
            else
                s[start++] = s[i]; 
        }   
    }
   
    for(int i=0; i < start/2; i++)
        if(s[i] != s[start-i-1])
            return false;
    return true;
}
 
int main()
{
    //char str[] = "A man, a plan, a canal: Panama";
    string str = "A man, a plan, a canal: Panama";
    cout << "isPalindrome is: "
         << isPalindrome(str)
         << endl;
    return 0;
}
 
