#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};
 
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void push(struct node** head_ref, int new_data)
{
   struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
   new_node->data  = new_data;
   new_node->next = (*head_ref);
  
   (*head_ref)    = new_node;
}
 
void printList(struct node *head)
{
   if(head == NULL)
   return;
   	
   printf("\nList \n");

   struct node *temp = head;
   while(temp != NULL)
   {
      printf("%d  ", temp->data);
      temp = temp->next;
   }
}
 
void reverse(struct node **head)
{
	struct node *prev = NULL;
	struct node *current = *head;
	struct node *next;
	while(current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}	
	*head = prev;
}

struct node* reverse_with_length(struct node *head, int k)
{
	struct node *prev = NULL;
	struct node *current = head;
	struct node *next;
	
	int count = 0;
	
	while(current && count < k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}	
	
	if(next != NULL)
	head->next = reverse_with_length(next, k);
	
	return prev;
}

void move(struct node **d, struct node **s)
{
	struct node *new_node = *s;
//	assert(newNode != NULL);
	
	*s = (*s)->next;
	 
	new_node->next = *d;
	*d = new_node;
	
}
void split(struct node *head, struct node **a, struct node **b)
{
	struct node *current = head;
	struct node *tmp1 = NULL;
	struct node *tmp2 = NULL;
	bool con = true;
	while(current)
	{
		if(con)
		move(&tmp1, &current);
		else		
		move(&tmp2, &current);
		
		con = !con;  
	    
	}
	*a = tmp1;
	*b = tmp2;
		
}

int main()
{
    struct node* head = NULL;
	
	for(int i=0;i<10;i++)
    push(&head, i);
 
    printList(head);
    
    reverse(&head);
    
    printList(head);
    
//    head = reverse_with_length(head, 2);
    
    struct node *head1=NULL;
    struct node *head2=NULL;
    
    split(head, &head1, &head2);
    
	printList(head1);
    printList(head2);
	
	getchar(); 
    return 0;
}

