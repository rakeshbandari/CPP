#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int binary(int arr[], int low, int high, int x)
{
	if(low > high)
		return -1;
	
	int mid = (low + high)/2;
	
	if(x == arr[mid]) 
		return mid;
	else if(x < arr[mid]) 
		return binary(arr, low, mid-1, x);
	else
		return binary(arr, mid+1, high, x);
}
int main()
{
	int arr[10] = {0,1,2,3,4,5,6,7,8,9} ;
	
	cout << binary(arr, 0, 10, 4);
	
 return 0;
}


