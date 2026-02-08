/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

*/

#include <bits/stdc++.h>
using namespace std;
 
bool isUgly(int n) {
    
    if(n<1) return false;
    
    while(n> 1){
        if(n % 2 == 0) n /= 2;
        else if(n % 3 == 0) n /= 3;
        else if(n %5 == 0) n/= 5;
        else{
            return false;
        }
    }
    return true;
}
int nthUglyNumber(int n) {
    int count = 0;
    int itr=1;
	while(count != n){
    	if(isUgly(itr)){
    		count++;
		}
		itr++;
	}
	return itr-1;    
}
int main()
{
	int n;
	cin >> n;
    cout << nthUglyNumber(n); 
    return 0;
}
