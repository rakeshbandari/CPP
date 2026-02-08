#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void push(struct node** head_ref, int new_data)
{
   struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
   new_node->data  = new_data;
   new_node->next = (*head_ref);
  
   (*head_ref)    = new_node;
}

void display(struct node* head){
	
	if(head == NULL) return;
	
	cout<< endl << "List : ";	
	
	while(head){
		cout << head->data << " ";
		head = head->next;
	}	
}

void reverse(struct node** head, struct node* b){
	 struct node *prev = b;
	 struct node *current = *head;
	 struct node *next;
	 
	 while(current){
	 	next = current->next;
	 	current->next= prev;
		prev = current;
		current = next;
	 }	 
	 *head = prev;
}

void reverse_ab(struct node* head, int a, int b){
	
	if(head == NULL) return;

	struct node* tmp = head;
	
	struct node* aPrev = NULL;
	struct node* bNext = NULL;
		
	int count = 1;
		
	while(tmp && ++count <= a)
		tmp = tmp->next;
	
	aPrev = tmp;	
	
	while(tmp && count++ <= b)
		tmp = tmp->next;
	
	bNext = tmp->next;	
	
	tmp->next = NULL;
		
	reverse(&aPrev->next, bNext);
		
}

int main()
{
	struct node* head = NULL;
	
	for(int i=0;i<10;i++)
    push(&head, i);
    
    display(head);
    
    int a=3,b=6;
    
    reverse_ab(head, a, b);
    
    display(head);
    
	return 0;
}
