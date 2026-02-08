#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void display(int arr[], int len)
{
   cout << endl << "Display : ";
  
   for(int i = 0; i < len ;i++)
   cout << arr[i] << " ";
   
   cout << endl;
}

void shuffle(int arr[], int len)
{
  for(int i=0;i<len;i++)
  arr[i] = rand()%100;  
}



////////////// bubbleSort ///////////////

void bubbleSort(int arr[], int n) 
{
      bool swapped = false;
      do 
      {     
            swapped = false;
            for (int i = 0; i < n - 1; i++) 
            {
                  if (arr[i] > arr[i + 1]) 
                  {
                        swap(&arr[i],&arr[i+1]);
                        swapped = true;
                  }
            }           
      }while(swapped);
}


////////////// selectionSort ///////////////

void selectionSort(int arr[], int n) 
{
      int i, j, minIndex;    

      for (i = 0; i < n - 1; i++) 
      {
            minIndex = i;
            for (j = i + 1; j < n; j++)
                  if (arr[j] < arr[minIndex])
                        minIndex = j;
            if (minIndex != i) 
            {
                  swap(&arr[i],&arr[minIndex]);
            }
      }
}

////////////// mergeSort ///////////////

void merge(int a[], int low, int mid, int high)
{

    int i = low, j = mid + 1, k = 0;
 
    int b[high-low+1];
 
    while (i <= mid && j <= high) 
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
  
    while (j <= high)
        b[k++] = a[j++];
        
    k--;
    while (k >= 0) 
    {
        a[low + k] = b[k];
        k--;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}


////////////// quickSort ///////////////

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int pivot = arr[right];
 
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) 
            {
                swap(&arr[i],&arr[j]);
                i++;
                j--;
            }
      };
 
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

////////////// heapSort ///////////////


void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--){
	    display(arr,n);
		cout << endl << "n : " << n << ", i : " << i; 
        heapify(arr, n, i);
    }
    
    cout << endl << "------";
    display(arr, n);
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
        display(arr, n);
    }
}

////////////// insertionSort ///////////////

void insertionSort(int arr[], int length) {
      int i, j;
      for (i = 1; i < length; i++) {
            j = i;
            while (j > 0 && arr[j - 1] > arr[j]) {
                  swap(&arr[j], &arr[j-1]);
                  j--;
            }
      }
}

int main()
{
  int len = 5;
  int *arr = new int[len];
  
  for(int i=0;i<len;i++)
  arr[i] = rand()%100;
  
   
  int ch;
  while(1)
  {
	  cout <<"1 - Bubble\n";
	  cout <<"2 - Selection\n";
	  cout <<"3 - Merge\n";
	  cout <<"4 - Quick\n";
	  cout <<"5 - Heap\n";
	  cout <<"6 - Insertion\n";
	  cout <<"9 - Shuffle\n"; 
	  cout <<"0 - Exit\n";      
	  display(arr, len);
	  cin >> ch;
	  switch(ch)
	  {
		  case 0:exit(1);
		  case 1:bubbleSort(arr,len);break;
		  case 2:selectionSort(arr,len);break;
		  case 3:mergeSort(arr,0,len-1);break;
		  case 4:quickSort(arr,0,len-1);break;
		  case 5:heapSort(arr,len);break;
		  case 6:insertionSort(arr,len);break;
		  case 9:shuffle(arr,len);break;
		  default:break;
	  }
  }	 
 return 0;
}




