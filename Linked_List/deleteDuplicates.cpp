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
 
void deleteDuplicates_Sorted(struct node * head) {
    
    if(head == NULL) return;
    
    struct node * current = head;
    struct node * tmp = NULL;
    
    while(current && current->next){
        if(current->data == current->next->data)
        {
            tmp = current->next;
            current->data = tmp->data;
            current->next = tmp->next;
            delete(tmp);
        }
        else
        current = current->next;
    }    
}



void deleteDuplicates_UnSorted(struct node *temp)
{																																														
	struct node *ptr1, *ptr2, *duplicate;
	ptr1 = temp;
	
	while (ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;
	
		while (ptr2->next != NULL)
		{
			if (ptr1->data == ptr2->next->data)
			{
				duplicate = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete(duplicate);
			}
			else
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}																		
}

void delete_LinkedList(struct node **head){
	struct node *tmp = *head;
	struct node *current = *head;
	while(current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*head = NULL;
}

int main()
{
    struct node* head = NULL;
	
	for(int i=0;i<=5;i++)
    push(&head, i);    
    push(&head, 5);    
    for(int i=5; i>=0; i--)
    push(&head, i);
     
    printList(head);    
    deleteDuplicates_Sorted(head);  
    printList(head);    
    
	delete_LinkedList(&head);
			
	for(int i=10; i>=0; i--)
    push(&head, rand()%10);
	
	printList(head);
	
	deleteDuplicates_UnSorted(head);
	
	printList(head);
	
	getchar(); 
    return 0;
}

