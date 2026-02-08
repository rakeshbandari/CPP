/*
https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
*/
#include <bits/stdc++.h>
using namespace std;
 
// Function to return the minimum number
// of jumps to reach arr[h] from arr[l]
int minJumps(int arr[], int n)
{
    if (n == 1)
        return 0;
    
    int res = INT_MAX;
    for (int i = n - 2; i >= 0; i--) 
	{
        if (i + arr[i] >= n - 1) 
		{
            int sub_res = minJumps(arr, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
 
    return res;
}

int minJumps2(int arr[], int n)
{
 
    if (n <= 1)
        return 0;
 
    if (arr[0] == 0)
        return -1;
 
    int maxReach = arr[0];
 
    int step = arr[0];
 
    int jump = 1;
 
    int i = 1;
    for (i = 1; i < n; i++) 
	{
        if (i == n - 1)
            return jump;
     
        maxReach = max(maxReach, i + arr[i]);
 
        step--;
 
        if (step == 0) 
		{        
            jump++;
 
            if (i >= maxReach)
                return -1;
 
            step = maxReach - i;
        }
    }
 
    return -1;
}
 
// Driver Code
int main()
{
    int arr[] = { 1, 3, 6, 3, 2, 3, 6, 8, 9, 5 };
    
	int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumps2(arr, n);
    
	return 0;
}
