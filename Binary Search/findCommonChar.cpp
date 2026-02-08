/*
Given an array words of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates). 
For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]

*/
#include <bits/stdc++.h>
using namespace std;



vector<string> commonChars(vector<string>& words) {
    
    vector<string> str;
    
    vector< vector<int> > arr(words.size(), vector<int> (26, 0));
	    
	/*
	for(int i=0; i < words.size(); i++)
	for(int j=0; j < words[i].length(); j++)
	arr[i][words[i][j]-'a']++;

    for(int i=0; i < 26; i++){
    	cout << char('a' + i)<< " ";	
	}
    
    cout << endl << endl;
    
	for(int i=0; i < arr.size(); i++){
    	for(int j=0; j < 26; j++)
			cout << arr[i][j] << " ";	
			cout << endl;
	}
  */  
    for(int i=0, j=0; i < words[0].length(); i++)
	{    
    	int n = words[0][i]-'a';
		
			
		bool check = false;
		
		for(j=0; j < words.size(); j++)
   	    {
	   	    if(arr[j][n] == 0)
			break;
	    }		
		
		if(j == words.size())
		{
			string s(1,words[0][i]);		
			str.push_back(s);
			
			for(int k=0; k < words.size(); k++)
			arr[k][n]--;
		}
	}	

    return str;
}

int main()
{
//	vector<string> str = {"bella","label","roller"};
	vector<string> str = {"acabcddd","bcbdbcbd","baddbadb","cbdddcac","aacbcccd","ccccddda","cababaab","addcaccd"};
	vector<string> s = commonChars(str); 
	
	for(int i=0; i < s.size(); i++)
		cout << s[i] << endl; 
		
    return 0;
}
 


