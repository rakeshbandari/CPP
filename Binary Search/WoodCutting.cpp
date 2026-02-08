/*

https://www.interviewbit.com/problems/woodcutting-made-easy/
 
*/
#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &A, int len){
	for(int i=0; i < len; i++){
		cout << A[i] << " ";
	}
	cout << endl << endl;
}
int maxIndex(vector<int> &A, int len)
{
    int max_val = 0, idx = 0;
    for(int i=0; i < len; i++){
        if(A[i] > max_val)
        {
            max_val = A[i]; 
            idx = i;
        }
    }    
    return idx;
}
int solve(vector<int> &A, int B) 
{
    int len = A.size();
    int i=0,start=0;

    while(start < B)
    {
        i = maxIndex(A, len);        
        A[i]--;
        start++;
    }
    return A[i];    
}


// Optimal Solution for Time Complexity with small difference
int solve_Optimal(vector<int> &A, int B) 
{

	int ret =0;	
	int max=0;	
	int maxpos;
		
	for (int i=0;i<A.size();i++)	
	{	
		if(A[i]>max)		
		{	
			max=A[i];			
			maxpos = i;		
		}	
	}	
	
	while(ret<B)
	{
	    ret++;
	    A[maxpos]--;
	    
	    for(int i=0;i<A.size();i++)
	    {
	        if(A[i] > A[maxpos])
	        {
	            A[i]--;
	            ret++;
	            
	        }
	    }
	}

	return A[maxpos];

}

int main()
{
	vector<int> arr = {77, 86, 141, 54, 52, 103, 142};
		
    int key = 82;
 		
    cout << solve(arr, key) << endl;
 
    return 0;
}
 


