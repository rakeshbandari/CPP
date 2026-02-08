#include <iostream>
#include <new>
#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
using namespace std;


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

bool flag = true;
void solve(node* head, node** head2){
    if(head == NULL) 
		return;
    
    solve(head->next, head2);
    
    if(head->data != (*head2)->data){
        flag = false;
        return;
    }            
    *head2 = (*head2)->next;                    
}
bool isPalindrome(node* head) {
     solve(head, &head);
     return flag;
}

void displayList(node *head){
   while (head != NULL) {
      cout << head->data << " ";
      head = head->next;
   }
   cout << endl;
}
    
int main(){
   int arr[] = {10, 15, 17, 15, 10}; 
     
   node *head = NULL;
   
   head = createList(arr, SIZE(arr));
   
   cout << "list: ";
   
   displayList(head);
   
   cout << "isPalindrome : " << isPalindrome(head);
   return 0;
}
