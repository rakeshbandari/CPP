#include <iostream>
#include <conio.h>
using namespace std;

template<class TERA>
class Binary
{
	protected:
	struct node{
		TERA data;
		node *lc;
		node *rc;
	}*root;
	int c,d;
	
	public:
	Binary(){
		root = NULL;
		menu();
	}
	void insert(node **);
	void preorder(node *);	
	void inorder(node *);
	void postorder(node *);
	void menu();	
};

template<class TERA>
void Binary<TERA>::menu(){	
	/*
	for(int i=0;i<10;i++){
		d = rand()%100;
		insert(&root);
	}
	*/
	while(1){
		system("cls");
		cout << "MENU\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Exit\nSelect : ";
		cin >> c;
		switch(c){
			case 1: cout << "Enter Data\n";
					cin >> d;
					insert(&root);
					break;
			case 2: cout << "PreOrder Output\n";
					preorder(root);
					getch();
					break;
			case 3: cout << "InOrder Output\n";
					inorder(root);
					getch();
					break;
			case 4: cout << "PostOrder Output\n";
					postorder(root);
					getch();
					break;
			case 5: exit(0);
		}
	}	
}

template<class TERA>
void Binary<TERA>::insert(node **r){
	if(*r == NULL){
		*r = new node;
		(*r)->data = d;
		(*r)->lc = (*r)->rc = NULL;
		return;
	}
	if(d == (*r)->data)
		return;
	if(d > (*r)->data)
		insert(&(*r)->rc);
	else
		insert(&(*r)->lc);
}

template<class TERA>
void Binary<TERA>::preorder(node *r){
	if(r != NULL){
		cout << r->data << "\t";
		preorder(r->lc);
		preorder(r->rc);
	}
}

template<class TERA>
void Binary<TERA>::inorder(node *r){
	if(r != NULL){
		inorder(r->lc);
		cout << r->data << "\t";		
		inorder(r->rc);
	}
}

template<class TERA>
void Binary<TERA>::postorder(node *r){
	if(r != NULL){		
		postorder(r->lc);
		postorder(r->rc);
		cout << r->data << "\t";
	}
}

int main()
{
	Binary<int> b1;
	b1.menu();
	return 0;
}
