#include<bits/stdc++.h>
using namespace std;

void reverse(string &s, int i, int j)
{
	int len = (i+j)/2;
	
	int k=i;
	
	while(k <= len)
	{
		swap(s[k], s[len-k-1]);
		k++;
	}
}

string reverseWords(string s) 
{
    int len = s.length();
	int start=0, end=0;
	
	while(start < len && s[start] == ' ')
	start++; 
	
	end = len;
	while(end >= 0 && s[end] == ' ')
	end--;	
	
    return s.substr(start, end);	
}
int main()
{
	string s = " the sky is blue ";
	
	string str = reverseWords(s);

	cout << str << endl;
	
	int len = str.length();
	
	for(int end=0, word=0; end < len; end++)
	{
		if(str[end] == ' ')
		{
			reverse(str, end-word, end);			
			word=0;
		}
		word++;		
	}
	
//	reverse(str, 0, len);
	cout << str;
	return 0;
}
