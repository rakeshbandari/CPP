/*program to print all of its root-to-leaf paths for a tree*/
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
void printArray(int ints[], int len)
{  
  for (int i=0; i<len; i++) {
    printf("%d ", ints[i]);
  }
  printf("\n");
} 
void _printPaths(struct node *root, int p[], int len)
{
	if(root == NULL)
	return;
	
	p[len] = root->data;
	len++;
	
	if(root->left == NULL && root->right == NULL)
	printArray(p,len);
	
	_printPaths(root->left, p, len);
	_printPaths(root->right, p, len);
}
void printPaths(struct node *root)
{
	int p[1000];
	_printPaths(root,p,0);
} 

int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
 
  printPaths(root);
 
  getchar();
  return 0;
}
