#include <bits/stdc++.h>
using namespace std;
 
void printSubStr(char* str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}
 

int longestPalSubstr(char* str)
{
	int maxLength = 0;
	int start = 0;
	
	int len = strlen(str);
 
    int low, high;
    
	for(int i=1; i<len; i++){
		
		low = i-1;
		high = i;
		
		while(low >= 0 && high < len && str[low] == str[high]){
			if(high - low + 1 > maxLength){
				maxLength = high - low + 1;				
				start = low;
			}				
			low--; high++;
		}			
	}
 
    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);
 
    return maxLength;
}
 
int main()
{
    char str[] = "forgeeksskeegfor";
    cout << "\nLength is: "
         << longestPalSubstr(str)
         << endl;
    return 0;
}
 
