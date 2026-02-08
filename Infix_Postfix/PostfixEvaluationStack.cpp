#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
class stack
{
	protected:
	struct node{
		int data;
		node *next;
	}*top;
	public:
	stack(){
		top = NULL;
	}
	void push(int);
	int pop();
	void display();
	int evaluatePostfix(char* exp);
};

void stack::push(int a){
	node *q=new node;
	q->data = a;
	q->next = top;
	top = q;
}

int stack::pop(){
	int a = top->data;
	top = top->next;
	return a;
}

void stack::display(){
	cout << endl;
	node *q=top;
	while(q!=NULL){
		cout << q->data << " ";
		q = q->next;
	}
}
int stack:: evaluatePostfix(char* exp) 
{  
    stack s1;
    for (int i = 0; exp[i]; ++i)
    {
    	cout << (int)exp[i] << " ";
	}
	cout << endl;
	for (int i = 0; exp[i]; ++i)
    { 
        if (isdigit(exp[i])){
			s1.push(exp[i]-'0'); 
        }
        else
        { 
            int val1 = s1.pop(); 
            int val2 = s1.pop();
            switch (exp[i]) 
            { 
	            case '+': s1.push(val2 + val1); break; 
	            case '-': s1.push(val2 - val1); break; 
	            case '*': s1.push(val2 * val1); break; 
	            case '/': s1.push(val2/val1); break;
	        } 
        } 
    } 
    return s1.pop(); 
}
int main()
{
	stack s1;
	char exp[] = "231*+9-"; 
    cout<<"postfix evaluation: "<< s1.evaluatePostfix(exp);
	return 0;
}
