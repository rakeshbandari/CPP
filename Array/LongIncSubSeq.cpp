#include <iostream>
#include <set>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;

void disp1(set<int> &S){
    cout << "First : ";
	for (const auto& element : S) {
    	std::cout << element << " ";
	}
	std::cout << std::endl;	
} 
void disp2(set<int> &S){
	cout << "Second : ";
    for (const auto& element : S) {
    	std::cout << element << " ";
	}
	std::cout << std::endl;	
}
int findLISLength(vector<int> arr, int n)
{
    set<int> S;
 
    for (int i = 0; i < n; i++)
    {
        if (S.find(arr[i]) != S.end()) {
            continue;
        }
 
        auto ret = S.insert(arr[i]);
        
        set<int>::iterator it;
        if (ret.second) {
            it = ret.first;
        }     
        
        disp1(S);

        if (++it != S.end()) {
            S.erase(it);
        }
        
        disp2(S);
    }
  
    return S.size();
}

  //Binary Search Method
int ceilArr(int tail[], int l, int r, int x)
{
    while(l < r)
     {
         int m = l + (r - l)/2;

         if(tail[m] >= x)
           r = m;
         else
          l = m + 1;
     }

    return r; 
}

int lengthOfLIS1(vector<int>& a) 
{
    int n = a.size();
    int len = 1;
    int tail[n];
    tail[0] = a[0];

    for(int i = 1; i < n; i++)
    {
        if(a[i] > tail[len - 1])
        {
           tail[len] = a[i];
           len++;
        }
        else
        {
           int c = ceilArr(tail, 0, len - 1, a[i]);
           tail[c] = a[i];
        }
    }
    return len;   
 }
   
//DP
int lengthOfLIS2(vector<int>& a) 
{
    int n = a.size();
    int lis[n];
    for(int i = 0; i < n; i++)
      lis[i] = 1;

    //computation in bottom up manner
    for(int i = 1; i < n; i++)
     {
         for(int j = 0; j < i; j++)
          {
             //store the maximum length till that element
              if(a[i] > a[j] && lis[i] < lis[j] + 1)
               lis[i] = lis[j] + 1;
          }
     }
     
    return *max_element(lis, lis + n); 
}
 
int main()
{
    int arr[] = { 2, 6, 3, 4, 1, 2, 9, 5, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    //cout << "The length of the LIS is " << findLISLength(arr, n);
    
    vector<int> a = { 2, 6, 3, 4, 1, 2, 9, 5, 8 };
    cout << "\nThe length of the LIS is " << lengthOfLIS1(a);
    cout << "\nThe length of the LIS is " << lengthOfLIS2(a);
    
    cout << "\nThe length of the LIS is " << findLISLength(a, n);
 
    return 0;
}




