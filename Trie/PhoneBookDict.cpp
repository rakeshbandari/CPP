#include <bits/stdc++.h>
using namespace std;
  
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

void display(struct TrieNode *curNode, string key)
{
	if(curNode->isEnd){
		cout << key << endl;
	}

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        TrieNode *nextNode = curNode->children[i];
        if (nextNode != NULL)
		{
			char s = i+'a';
        	display(nextNode, key + s);
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
		
		cout << "\nFor : " << prefix << endl;
		display(curNode, prefix);
		cout << endl;	
		
		prevNode = curNode;
	}		
}


int main()
{
	struct TrieNode *root = getNode();
	
	vector<string> arr = {"abcd","abce","abrf"};		
	
	for(int i=0; i < arr.size(); i++)
	insert(root, arr[i]);

	displayDict(root, "abc");			
//	cout << (search(root, "abce") ? "True" : "False");
			
    return 0;
}
