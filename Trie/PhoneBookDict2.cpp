#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> vec;
  
const int ALPHABET_SIZE = 26;
  
struct TrieNode{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isEnd;
};

struct TrieNode * getNode()
{
	struct TrieNode *new_node = new TrieNode();
	
	for(int i=0; i < ALPHABET_SIZE; i++)
	new_node->children[i] = NULL;
	
	new_node->isEnd = false;
}

void insert(struct TrieNode *root, string str)
{
	struct TrieNode *itr = root;
	
	for(int i=0; i < str.length(); i++)
	{
		int idx = str[i]-'a';
		
		if(itr->children[idx] == NULL)
		itr->children[idx] = getNode();
		
		itr = itr->children[idx];
	}
	itr->isEnd = true;
}

bool search(struct TrieNode *root, string str)
{
	struct TrieNode *itr = root;
	
	for(int i=0; i < str.length(); i++)
	{
		int idx = str[i]-'a';
		
		if(itr->children[idx] != NULL)
		   itr = itr->children[idx];
		else
			return false;		
	}
	
	return itr->isEnd;
}

void display(struct TrieNode *curNode, string key, vector<string> &sub)
{
	if(curNode->isEnd){
		sub.push_back(key);
	}

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        TrieNode *nextNode = curNode->children[i];
        if (nextNode != NULL)
		{
			char s = i+'a';
        	display(nextNode, key + s, sub);
		}
    }
}
void displayDict(struct TrieNode *root, string str)
{
	TrieNode *prevNode = root;
	
	string prefix = "";
	for(int i=0; i < str.length(); i++)
	{
		prefix += str[i];
		
		TrieNode *curNode = prevNode->children[str[i]-'a'];
		
		if(curNode == NULL){
			break;
		}
		
		vector<string> sub;
		
		display(curNode, prefix, sub);
		
		vec.push_back(sub);
		sub.clear();
		
		prevNode = curNode;
	}		
}

void displayVec()
{
	for(int i=0; i < vec.size(); i++){
		for(int j=0; j < vec[0].size(); j++)
		cout << vec[i][j] << endl;
		cout << endl << endl;
	}
}
int main()
{
	struct TrieNode *root = getNode();
	
	vector<string> arr = {"abcd","abce","abrf"};		
	
	for(int i=0; i < arr.size(); i++)
	insert(root, arr[i]);

	displayDict(root, "abc");	
	
	displayVec();		
//	cout << (search(root, "abce") ? "True" : "False");
			
    return 0;
}
