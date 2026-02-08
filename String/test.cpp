#include <bits/stdc++.h>
using namespace std;


int isVowel(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return 1;
    return 0;
}

int subString(string s, int n)
{
	long long count=0;	
	int vcount=0;	
	int ccount=0;	
	for(int i=0;i<s.size();i++)	
	{	
		if(isVowel(s[i]))		
		{		
			vcount++;						
			count=count + ccount;			
		}		
		else if(!isVowel(s[i]))		
		{		
			ccount++;			
			count=count+vcount;			
		}			
	}	
	cout << count << " " << vcount << " " << ccount << endl;
	return (count%1000000007);         
}

 
int main()
{
	string st = "aba";
    int res = subString(st, st.length()-1);
    cout << res;
    return 0;
}
 
