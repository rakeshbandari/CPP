// https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/

#include <bits/stdc++.h>
using namespace std;
void getUnion(int a[], int n, int b[], int m)
{
     
    // Defining set container s
    set<int> s;
   
    // Inserting array elements in s
    for (int i = 0; i < n; i++)
      s.insert(a[i]);
   
    for (int i = 0; i < m; i++)
        s.insert(b[i]);
       
      
    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr << " ";
        
    cout << endl << "Size : " << s.size();    
}
 


int main()
{
    int a[9] = { 1, 2, 5, 6, 2, 3, 5, 7, 3 };
    int b[10] = { 2, 4, 5, 6, 8, 9, 4, 6, 5, 4 };
 
    getUnion(a, 9, b, 10);
}


/*
Time Complexity: O(m * log(m) + n * log(n))
*/
