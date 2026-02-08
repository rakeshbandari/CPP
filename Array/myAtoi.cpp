/*
8. String to Integer (atoi) LeetCode
*/
#include <bits/stdc++.h>
using namespace std;

int myAtoi2(string s) 
{
    int len = s.length();
    
	vector<int> a;
    
	bool flag = true;
    
    for(int i=0;i<len;i++)
    {
       if(s[i] == '-')flag = false;
       
       if(s[i] >= '0' && s[i] <= '9'){
       	 a.push_back(s[i]-48);
	   }       
       
       if(s[i] >= 'a' && s[i] <= 'z' && a.size() == 0)
           return 0;                         
       
    }
    
    len = 0;
    int result=0;
    
    while(len < a.size()){
        result = result * 10 + a[len++];
    }
    
    return (flag? result : -result);
}  

int myAtoi(string s) {
	int i=0;
	int n = s.length();
	
	while(s[i]==' ' && i<n)   //skipping white spaces
		i++;
	
	int sign = s[i]=='-'?-1:1;
	
	if (s[i] == '+' || s[i] == '-') 
		i++;
	
	int num=0;
	
	while(i< n && isdigit(s[i])){
		// check if the NUM obtained after the shift and add operation will cause overflow
		// if overflow can occur, send the min limit if negative number, else max limit 
		if(num > (INT_MAX-(s[i]-'0'))/10)
			return sign==-1?INT_MIN:INT_MAX;
		
		num = num*10 + (s[i]-'0');
		
		i++;
	}
	// send result with correct polarity as given in string
	return sign*num;
}
	  
int main(){
   
   cout << myAtoi("432") << endl;
   cout << myAtoi("4193 with words") << endl;
   cout << myAtoi("words and 987") << endl;
   cout << myAtoi("912834723") << endl;
   
   return 0;
}
