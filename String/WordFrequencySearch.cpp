/*
There is a collection of input strings and a collection of query strings. For each query string, determine how many times it occurs in the list of input strings. Return an array of the results.

Example
 strings = {"ab","ab","abc"}
 queries = {"ab","abc","bc"}


There are 2 instances of 'ab', 1 of 'abc' and  0 of 'bc'. For each query, add an element to the return array, result = [2,1,0] .

*/
#include <bits/stdc++.h>
using namespace std;
 
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    unordered_map<string, int> wordFreq;
    
    for(int i=0; i < strings.size(); i++)
        wordFreq[strings[i]]++;
    vector<int> count;
        
    for(int i=0; i < queries.size(); i++)
        count.push_back(wordFreq[queries[i]]);
    return count;            
}

int main()
{
	vector<string> strings = {"ab","ab","abc"};
    vector<string> queries = {"ab","abc","bc"};
    
	vector<int> count = matchingStrings(strings,queries);
    
    for(int i=0;i<count.size();i++)
	cout << count[i] << " ";
    
    return 0;
}
