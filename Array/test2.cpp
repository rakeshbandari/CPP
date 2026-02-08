#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>
#include<algorithm>

#include <bits/stdc++.h>
using namespace std;

bool comp( const pair<string,int>& a,  const pair<string,int> &b){
    return a.first < b.first;
}

bool comp2( const pair<string,int>& a,  const pair<string,int> &b){
	if(a.second == b.second)
	return false;
	
    return a.second > b.second;
}

int main (){
    unordered_map <string,int> ump;
    
  //  vector<string> R ={"notebook","notebook","mouse","keyboard","mouse"};
    
    vector<string> R;
    
    
    fstream file;
    string word, t, q, filename;  
    filename = "wordTxt.txt";
    file.open(filename.c_str());    
    while (file >> word)
    {        
    //    cout << word << endl;
    	R.push_back(word);
    }    
    
    
  //  sort(R.begin(),R.end());
    
    for(auto x:R){
        ump[x]++;
    }
    
    vector<pair<string,int> > b;
    
    for(auto x:ump){
        b.push_back(x);
    }
    
    sort(b.begin(),b.end(),comp);
   // sort(b.begin(),b.end(),comp2);
    
    for(auto x:b)
        cout<< x.first<<" " <<x.second <<" "<<endl;
     
}
