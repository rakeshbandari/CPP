#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void MinHeapify(int arr[], int i, int n)
{
	int smallest = i;
	int left  = 2*i+1;
    int right = 2*i+2;
	
	if(left < n && arr[left] < arr[smallest])	
	smallest = left;
	
	if(right < n && arr[right] < arr[smallest])	
	smallest = right;
	 
	if(smallest != i)
	{
		swap(&arr[i], &arr[smallest]);
		MinHeapify(arr, smallest, n);
	} 
}
void convertMinHeap(int arr[], int n)
{
	for(int i=n/2-1;i>=0;i--)
	MinHeapify(arr,i,n);
	
	for(int i=n-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		MinHeapify(arr,0,i);
	}
}

void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	cout << arr[i] << " ";
}

int main()
{
    // array representing Min Heap
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Min Heap array : ");
    printArray(arr, n);
 
    convertMinHeap(arr, n);
 
    printf("\nMax Heap array : ");
    printArray(arr, n);
 
    return 0;
}
