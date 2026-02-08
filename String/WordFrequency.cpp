// C++ program to find freq of every word using
// unordered_map
#include <bits/stdc++.h>
using namespace std;
 
// Prints frequencies of individual words in str
void printFrequencies(const string &str)
{
    unordered_map<string, int> wordFreq;
 
    stringstream ss(str);
    string word;
    while (ss >> word)
        wordFreq[word]++;
 
    unordered_map<string, int>:: iterator p;
    for (p = wordFreq.begin(); p != wordFreq.end(); p++)
        cout << "(" << p->first << ", " << p->second << ")\n";
}
 
// Driver code
int main()
{
    string str = "geeks for geeks geeks quiz "
                 "practice qa for";
    printFrequencies(str);
    return 0;
}
