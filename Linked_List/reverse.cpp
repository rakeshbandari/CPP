#include <bits/stdc++.h>
using namespace std;
#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

struct node {
   int data;
   struct node *next;
};

node *createList(int *arr, int n){
   node *head, *p;
   p = head = new node;
   head->data = arr[0];
   head->next = NULL;
   for (int i = 1; i < n; ++i) {
      p->next = new node;
      p = p->next;
      p->data = arr[i];
      p->next = NULL;
   }
   return head;
}

void print(struct node* head)
{
	if(head == NULL) return;
	
	cout << endl << "List : ";
    struct node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
 
struct node * reverse(struct node * head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct node * prev = NULL; 
    struct node * current = head; 
    struct node * next;
	
	while (current != NULL) {
        next = current->next;            
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;   

    return head;
}
    
struct node * reverse_recursion(struct node * head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct node * rest = reverse_recursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

int main()
{
   int arr[] = {10, 15, 17, 25, 30};   
   node *head = NULL;   
   head = createList(arr, SIZE(arr));
   print(head);
   
   head = reverse(head);
   
   print(head);
   
   head = reverse_recursion(head);
   
   print(head);
   
   return 0;
}
