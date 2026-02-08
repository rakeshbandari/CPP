#include <bits/stdc++.h>
using namespace std;
 
const int ALPHABET_SIZE = 26;

struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isEnd;
};

struct TrieNode * getNode()
{
	struct TrieNode *new_node = new TrieNode;
	
	new_node->isEnd = false;
	
	for(int i=0; i < ALPHABET_SIZE; i++)
		new_node->children[i] = NULL;	
		
	return new_node;	
}

void insert(struct TrieNode *root, string str)
{
	 struct TrieNode *current = root;
	 
	 for(int i=0; i < str.length(); i++)
	 {
		if(current->children[str[i]-'a'] == NULL)
			current->children[str[i]-'a'] = getNode();		
		 current = current->children[str[i]-'a'];	 	
	 }
	 current->isEnd = true;	 	
} 

bool search(struct TrieNode *root, string str)
{
	struct TrieNode *current = root;
	
	for(int i=0; i < str.length(); i++)
	{
		if(current->children[str[i]-'a'] != NULL)
		current = current->children[str[i]-'a'];
		else
		return false;	
	}
	
	return current->isEnd;	
} 

int main()
{
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct TrieNode *root = getNode();
 
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
 
    search(root, "the")? cout << "Yes\n" : cout << "No\n";
    
    search(root, "these")? cout << "Yes\n" : cout << "No\n";
    
	return 0;
}
