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

void displayContactsUtil(TrieNode *curNode, string prefix)
{
    if (curNode->isEnd)
        cout << prefix << endl;
 
    for (char i = 'a'; i <= 'z'; i++)
    {
        TrieNode *nextNode = curNode->children[i];
        if (nextNode != NULL)
            displayContactsUtil(nextNode, prefix + (char)i);
    }
}
  
void displayContacts(TrieNode *root, string str)
{
    TrieNode *prevNode = root;
  
    string prefix = "";
    int len = str.length();
  
    int i;
    for (i=0; i<len; i++)
    {
          prefix += (char)str[i];
  
        char lastChar = prefix[i];
  
        TrieNode *curNode = prevNode->children[lastChar];
  
        if (curNode == NULL)
        {
            cout << "\nNo Results Found for "<< prefix << endl;
            i++;
            break;
        }
  
        cout << "\nSuggestions based on " << prefix  << endl;
        displayContactsUtil(curNode, prefix);
          
        prevNode = curNode;
    }
  
    for (; i<len; i++)
    {
        prefix += (char)str[i];
        cout << "\nNo Results Found for " << prefix << endl;
    }
}

int main()
{
    string keys[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct TrieNode *root = getNode();
 
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
 
    search(root, "geeksfortest")? cout << "Yes\n" : cout << "No\n";
    
	
	displayContacts(root, "gee");
    
	return 0;
}
