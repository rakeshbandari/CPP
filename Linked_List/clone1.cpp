#include <iostream>
using namespace std;
struct list 
{
	int data;
	list *next,*random;
};
list* newnode(int data)
{
	list* node=new list;
	node->data=data;
	node->next=node->random=NULL;
	return node;
}
list* clone(list* org)
{
	list* head=org,*copy,*h;
	copy=newnode(head->data);
	
	h=copy;

	head=head->next;
	/*loop for next pointers*/
	while(head!=NULL)
	{
	copy->next=newnode(head->data);
	copy=copy->next;
	head=head->next;
	}
	
	head=org,copy=h;
	/*loop for random pointers*/
	while(head!=NULL)
	{
		copy->random=head->random;
		head=head->next;
		copy=copy->next;
	}
	
return h;
}
int main() 
{
list* o,*ans;
/*to fill values*/
o=newnode(1);
o->next=newnode(2);
o->next->next=newnode(3);
o->next->next->next=newnode(4);
o->next->next->next->next=newnode(5);
o->next->next->next->next->next=NULL;
/*to set random pointers*/
o->random=o->next->next;
o->next->random=o;
o->next->next->random=o->next->next->next->next;
o->next->next->next->random=o->next->next;
o->next->next->next->next->random=o->next;

ans=clone(o);//call clone function

list*head=ans;
//print
while(head!=NULL)
{	if(head->next)
	cout<<head->data<<"->"<<head->next->data<<" -> "<<head->random->data<<endl;
	else
	cout<<head->data<<"->NULL -> "<<head->random->data<<endl;
     
	head=head->next;
}

return 0;
}
