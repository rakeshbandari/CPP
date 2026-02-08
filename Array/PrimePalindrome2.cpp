#include <bits/stdc++.h>
using namespace std;

int reverse(int num){
	int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
int primePalindrome(int n)
{
	
    int x;
    int mirroredNmb;
    int temp;
    
    if(n <= 1)
    {
        n = 2;
    }

    while(true)
    {         

        mirroredNmb = reverse(n);
 
        
        if(mirroredNmb == n)
        {
            temp = sqrt(n);
            for(x=2; x <= temp; ++x)
            {
                if((n % x) == 0)
                {
                    break;
                }
            }
			
            if(x > temp)
            {
                return n;    
            }                    
        }
        
        ++n;
      

        if(n >= 10000000 && n <= 100000000)
        {
            n = 100030001;
        }
    }
}

int main()
{
   int n;
   cin >>n;
   cout << endl << primePalindrome(n);
   return 0;
}  
