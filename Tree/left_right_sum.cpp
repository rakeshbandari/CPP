#include<iostream>
using namespace std;

#include <stdio.h>
 
int equilibrium(int arr[], int n)
{
  int i, j;
  int leftsum, rightsum;
 
  /* Check for indexes one by one until an equilibrium
    index is found */
  for ( i = 0; i < n; ++i)
  {
    leftsum = 0;  // initialize left sum for current index i
    rightsum = 0; // initialize right sum for current index i
 
    /* get left sum */
    for ( j = 0; j < i; j++)
      leftsum  += arr[j];
 
    /* get right sum */
    for( j = i+1; j < n; j++)
      rightsum += arr[j];
 
    /* if leftsum and rightsum are same, then we are done */
    if (leftsum == rightsum)
      return i;
    }
 
  /* return -1 if no equilibrium index is found */
  return -1;
}

 
int equilibrium1(int arr[], int n)
{
   int sum = 0;      // initialize sum of whole array
   int leftsum = 0; // initialize leftsum
   int i;
 
   /* Find sum of the whole array */
   for (i = 0; i < n; ++i)
        sum += arr[i];
 
   for( i = 0; i < n; ++i)
   {
 
      if(leftsum == sum)
        return i;
 
      sum -= arr[i]; // sum is now right sum for index i

      leftsum += arr[i];
      
   }
 
    /* If no equilibrium index found, then return 0 */
    return -1;
}
 
int main()
{
	int a[]={1,2,3,4,4,3,2,1};
	//int a[]={-7,1,5,2,-4,3,0};
	int len = sizeof(a)/sizeof(a[0]);
	

    cout << equilibrium1(a,len);
	return 0;
}
