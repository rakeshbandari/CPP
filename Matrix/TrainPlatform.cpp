#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void sorting(int arr[], int dep[], int n){	
	bool swapped = false;
      do 
      {     
            swapped = false;
            for (int i = 0; i < n - 1; i++) 
            {
                  if (arr[i] > arr[i + 1]) 
                  {
                        swap(&arr[i],&arr[i+1]);
                        swap(&dep[i],&dep[i+1]);
                        swapped = true;
                  }
            }           
      }while(swapped);
}


int findPlatform(int arr[], int dep[], int n){
	
	int plat_needed = 1, result = 1;
    int i = 1, j = 0;
   // sorting(arr,dep,n);
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        }
        else if (arr[i] > dep[j]) {
            plat_needed--;
            j++;
        }
 
        if (plat_needed > result)
            result = plat_needed;
    }
    
	return result;
}
int main()
{
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n);
    return 0;
}
