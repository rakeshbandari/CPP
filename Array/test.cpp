/*
There is a collection of input strings and a collection of query strings. For each query string, determine how many times it occurs in the list of input strings. Return an array of the results.

Example
 strings = {"ab","ab","abc"}
 queries = {"ab","abc","bc"}


There are 2 instances of 'ab', 1 of 'abc' and  0 of 'bc'. For each query, add an element to the return array, result = [2,1,0] .

*/
#include <bits/stdc++.h>
using namespace std;

void dis(vector<string> &tran)
{
	cout << endl;
	
	for(string s : tran)
	cout << s << " ";
	
	cout << endl;	
} 

void diss(vector<string,int> &tran)
{
	cout << endl;
	
	
    for(auto x : tran)
    {
        cout << x.first << " "<<x.second << endl;

    }
	
	cout << endl;	
} 


bool comp(const pair<string,int> &a, const pair<string,int> &b)
{
    return a.second > b.second;
}
vector<string> groupTransactions(vector<string> transactions) {
    int len = transactions.size();
  
    vector<string> result;
    
    unordered_map<string, int> wordF;

    for(int i=0; i < len; i++)
        wordF[transactions[i]]++;
    
    vector<string,int> vec;
    for(auto x : wordF)
    {
        vec.push_back(x);
    }
    
//	sort(vec.begin(),vec.end(),comp)
	
	diss(vec);
	
    for(auto x : vec)
    {
        stringstream ss;
        string s;
    
        ss << x.second;        
        ss >> s;
        string str = x.first + " " + s;
        result.push_back(str);
    }

    return result;
}


int main()
{
	vector<string> strings = {"notebook","notebook","mouse","keyboard","mouse"};
    

    
	vector<string> count = matchingStrings(strings);
    

    return 0;
}
