#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *newNode(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void push(struct node **head_ref, int data)
{
	struct node *new_node = newNode(data);
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void display(struct node *head)
{
	cout<<endl<<"Display :";
	struct node *temp = head;
	while(temp)
	{
		cout<< " " << temp->data;
		temp = temp->next;
	}
	cout<<endl;
}

void shuffle(struct node **head)
{
	struct node *current = *head;
	struct node *tmp;
	while(current)
	{
		tmp = current->next;		
		free(current);
		current = tmp;
	}
	*head = NULL;
    for(int i=0;i<10;i++)
    push(head,rand()%100);
}


/////////////////////////////////////////////////////////////////////





/////////////////////////////////////////////////////////////////////

void splitting(struct node *head, struct node **a, struct node **b)
{
    if (head==NULL || head->next==NULL)
	{
		*a = head;
		*b = NULL;
		return;
    }

    struct node *slow = head;
    struct node *fast = head->next;	
	  
    while(fast != NULL && fast->next != NULL)
    {
		slow = slow->next;
		fast = fast->next->next;
	}
	
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}

struct node *sort_merge(struct node *a, struct node *b)
{
	 if(a == NULL)
	 	 return b;
	 else if (b == NULL)
		 return a;
		 
	 struct node *current = NULL;
	 
	 if(a->data <= b->data)
	 {
		 current = a;
		 current->next = sort_merge(a->next, b);
	 }
	 else
	 {
		 current = b;
		 current->next = sort_merge(a, b->next);
	 }   
	 return current;
}

void MergeSort(struct node **head_ref)
{
   	 struct node *head = *head_ref;
     struct node *a;
     struct node *b;
     
     if(head == NULL || head->next == NULL)
      return;
      
     splitting(head,&a,&b);
     
     MergeSort(&a);
     MergeSort(&b);
      
     *head_ref = sort_merge(a, b); 
}

////////////////////////////////////////////////////////////////


struct node *getTail(struct node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
 
struct node *partition(struct node *head, struct node *end,
                       struct node **newHead, struct node **newEnd)
{
    struct node *pivot = end;
    struct node *prev = NULL, *cur = head, *tail = pivot;
 
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;  
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            if (prev)
                prev->next = cur->next;
            struct node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    (*newEnd) = tail;
 
    return pivot;
}
 
 

struct node *quickSortRecur(struct node *head, struct node *end)
{
    if (!head || head == end)
        return head;
 
    node *newHead = NULL, *newEnd = NULL;
 
    struct node *pivot = partition(head, end, &newHead, &newEnd);
 
    if (newHead != pivot)
    {
        struct node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        newHead = quickSortRecur(newHead, tmp);
 
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }
 
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}
 
void quickSort(struct node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}


///////////////////////////////////////////////////////////////

void Bubble(struct node **head_ref)
{
   struct node *current = *head_ref;
   struct node *prev = *head_ref;
   struct node *tmp;
   int swapped;
   
   do
    {
		current = *head_ref;
		prev = current;
        swapped = 0;   
        while (current->next != NULL)
        {
			if(current->data > current->next->data)
			{
				
				if(current == *head_ref)
				{
					tmp = *head_ref;
					*head_ref = (*head_ref)->next;
					tmp->next = (*head_ref)->next;
					(*head_ref)->next = tmp;
					current = *head_ref;
				}
				else if(current->next->next == NULL)
				{
					tmp = current;
					prev->next = current->next;
					current = current->next;
					current->next = tmp;
					tmp->next = NULL;
					
				}
				else
				{
					tmp = current;
					prev->next = current->next;
					current = current->next;
					tmp->next = current->next;
					current->next = tmp;	
			    }
				swapped = 1; 			
			}
			prev = current;
			current = current->next;
		    
		//	display(*head_ref);
        } 

    }while (swapped);
}


///////////////////////////////////////////////////////////////
int main()
{
  struct node *head = NULL;
  for(int i=0;i<11;i++)
  push(&head,rand()%100);
  
  int ch;
  while(1)
  {
	  cout <<"1 - Bubble\n";
	  cout <<"2 - Selection\n";
	  cout <<"3 - Merge\n";
	  cout <<"4 - Quick\n";
	  cout <<"5 - Heap\n";
	  cout <<"6 - Shuffle\n"; 
	  cout <<"0 - Exit\n";      
	  display(head);
	  cin >> ch;
	  switch(ch)
	  {
		  case 0:exit(1);
		  case 1:Bubble(&head);break;
		  case 2:break;
		  case 3:MergeSort(&head);break;
		  case 4:quickSort(&head);break;
		  case 5:break;
		  case 6:shuffle(&head);break;
		  default:break;
	  }
  }	 
 return 0;
}


