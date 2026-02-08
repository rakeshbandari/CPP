#include <bits/stdc++.h>
using namespace std;
  
struct Node {
    int data;
    Node* next;
};
  
Node* getNode(int data)
{
    Node* newNode = new Node;  
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
  
void findNthFromLast(Node* head, int n, int* count, Node** nth_last)
{
    if (!head)
        return;
  
    findNthFromLast(head->next, n, count, nth_last);
  
    *count = *count + 1;

    if (*count == n)
        *nth_last = head;
}
  
void findNthFromLastUtil(Node* head, int n)
{
    Node* nth_last = NULL;
    int count = 0;
  
    findNthFromLast(head, n, &count, &nth_last);
  
    if (nth_last != NULL)
        cout << "Nth node from last is: "
             << nth_last->data;
    else
        cout << "Node does not exists";
}
  
int main()
{
    // linked list: 4->2->1->5->3
    Node* head = getNode(4);
    head->next = getNode(2);
    head->next->next = getNode(1);
    head->next->next->next = getNode(5);
    head->next->next->next->next = getNode(3);
  
    int n = 2;
  
    findNthFromLastUtil(head, n);
  
    return 0;
}
