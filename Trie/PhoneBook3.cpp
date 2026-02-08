#include <bits/stdc++.h>
using namespace std;
  
const int ALPHABET_SIZE = 26;


struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isEnd;
};

TrieNode *root = NULL;

struct TrieNode * getNode()
{
	struct TrieNode *new_node = new TrieNode;
	
	new_node->isEnd = false;
	
	for(int i=0; i < ALPHABET_SIZE; i++)
		new_node->children[i] = NULL;	
		
	return new_node;	
}

void insert(string str)
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


void displayContactsUtil(TrieNode *curNode, string prefix)
{
    if (curNode->isEnd)
        cout << prefix << endl;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        TrieNode *nextNode = curNode->children[i];
        if (nextNode != NULL)
		{
			char s = i+'a';
        	displayContactsUtil(nextNode, prefix+s);
		}
    }
}

void displayContacts(string str)
{
    TrieNode *prevNode = root;
  
    string prefix = "";
    int len = str.length();
  
    int i;
    for (i=0; i<len; i++)
    {
        prefix += str[i];

        TrieNode *curNode = prevNode->children[str[i]-'a'];
  
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
  
void insertIntoTrie(string contacts[],int n)
{
    root = new TrieNode();

    for (int i = 0; i < n; i++)
        insert(contacts[i]);
}
  
int main()
{
    string contacts[] = {"gforgeeks" , "geeksquiz"};
  
    int n = sizeof(contacts)/sizeof(string);
  
    insertIntoTrie(contacts, n);
  
    string query = "geekk";

    displayContacts(query);
  
    return 0;
}
