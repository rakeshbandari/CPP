// Search an element in sorted and rotated
// array using single pass of Binary Search
#include <bits/stdc++.h>
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    int len = n1+n2;
    int k = 0;
    int pv;
    int i = 0,j = 0;
    while(i < n1 && j < n2)
	{
        int mn;
        if(nums1[i] < nums2[j])
			mn = nums1[i++];
		else
			mn = nums2[j++];
			
        if(len%2 == 1 && k == len/2)
		{
            return mn*1.0;
        }else if(k == len/2){
            return (mn+pv)/2.0;
        }
        k++;
        pv = mn;
    }
    while(i<n1){
        int mn = nums1[i];
        if(len%2 == 1 && k == len/2){
            return mn*1.0;
        }else if(k == len/2){
            return (mn+pv)/2.0;
        }
        pv = mn;
        i++;
        k++;
    }
    while(j<n2){
        int mn = nums2[j];
        if(len%2 == 1 && k == len/2){
            return mn*1.0;
        }else if(k == len/2){
            return (mn+pv)/2.0;
        }
        pv = mn;
        j++;
        k++;
    }
    return double(0);
}
    

int main()
{
	  
    return 0;
}
 


