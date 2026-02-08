#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    string ans = "";
    
	int i = s.length()-1;
    
	while( i >= 0 )
	{
        if(s[i] == ' ')
            i--;
        else
		{
            int j = i;
            
            while( i >= 0 and s[i] != ' ')
			{
                i--;
            }
            
            if(ans.length() > 0)
			{
                ans += " ";
            }
            
            for(int k=i+1; k<=j; k++)
			{
                ans += s[k];
            }
        }
    }
    return ans;
}
int main()
{
	string s = "the sky is blue";
	
	string str = reverseWords(s);

	cout << str << endl;

	return 0;
}
