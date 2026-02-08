/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]

*/
#include<bits/stdc++.h>
using namespace std;



int hashI[26]={0};

void updateHashI(string str)
{
	hashI[26]={0};
	for(int i=0; i< str.length(); i++) 
	hashI[str[i]-'a']++;
}

bool isAnagram(string children)
{
	int hashTemp[26]={0};	
	for(int i=0; i< children.length(); i++) 
	hashTemp[children[i]-'a']++;
		
	for(int i=0; i<26;i++)
	if(hashI[i] != hashTemp[i])
	return false;	
	return true;	
}
int main()
{
	vector<vector<string>> ans;
	
	vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
	
	for(int i=0; i < strs.size(); i++)
	{
		string parent = strs[i];
		
		updateHashI(parent);
		vector<string> vec;
		vec.push_back(parent);
		for(int j=0; j < strs.size(); j++)
		if(i != j)
		{
			string children = strs[j];
			if(isAnagram(children))
			{
				vec.push_back(children);
			}
		}
		ans.push_back(vec);		
	}
	
	for(int i=0; i<ans.size();i++)
	{
		for(int j=0; j<ans[0].size();j++)
		cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}
