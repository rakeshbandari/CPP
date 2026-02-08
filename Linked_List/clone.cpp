#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* prev;
	struct node* next;
};
 
void push(struct node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    /* 2. put in the data  */
    new_node->data  = new_data;
 
    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    /* 4. change prev of head node to new node */
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;
 
    /* 5. move the head to point to the new node */
    (*head_ref)    = new_node;
} 
void display(struct node *head)
{
	cout << endl;
	struct node *temp;
	while(temp)
	{
		cout << temp->data <<" ";
		temp = temp->next;
	}
} 

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    head
    return 0;
}

