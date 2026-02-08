#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n) 
{
      int i, max = 0;    
      for (i = 0; i < n ; i++) 
      {
      	if(arr[i] > max)
        max = arr[i];
      }
      return max;
}


int main()
{
	//int arr[] = {3,0,0,2,0,4};  
	//int arr[] = {8,8,2,4,5,5,1};    
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};   
   
	int N = sizeof(arr) / sizeof(arr[0]);
	
	int M = getMax(arr,N);    
		
	
	vector<vector<int> > a( M , vector<int> (N, 0)); 
	
	for(int i=0; i < N; i++){	
		for(int j = M-1, k = arr[i]; j >= 0 && k-- > 0; j--){
			a[j][i] = 1;			
		}
    }

/*
	for(int i=0; i < M; i++){
		for(int j=0; j < N; j++)
		cout << a[i][j] << " ";
		cout << endl;	
	}	
	*/
	
	int count = 0;

	for(int i=0; i < M; i++){
		
		int start = 0, end = N-1;
		
		while(start < N){
			if(a[i][start++] == 1)break;						
        }
		while(end >= 0){
			if(a[i][end--] == 1)break;
		}
		while(start <= end){
			if(a[i][start++] == 0)count++;
		}
	}	
	cout << count;
    return 0;
}
