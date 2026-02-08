#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    if(n<2)
        return 0;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return 0;
    return 1;
}

// brute force
int countPrimes(int n) {
  
    int count = 0;  
   
    for(int i = 2; i < n; i++)
        if(is_prime(i)){
            count++;
        }               
    
    return count;
}


// By Finding non-primes and making them false so that we need not waste time to check that numbers are prime or not
int countPrimes3(int n) {
	vector<bool> primes(n, true);
	for (int i = 2; i * i < n; i++)
	{
		if (primes[i])
		{
			for (int j = i, product = 0; (product = i * j) < n; j++)
			{
				primes[product] = false;
		//		cout << i << " * " << j << " : "<< product << endl;
			}
		}
	}

	int result = 0;
	for (int i = 2; i < n; i++)
	{
		if (primes[i])
		{
			++result;
	//		cout << i << " ";
		}
	}
	return result;
}

int main()
{
   int n;
   cin >>n;  // input 5000000,  observe the time taken in both cases
  // cout << endl << countPrimes(n) << endl;
   cout << "\ncount : " << countPrimes3(n) << endl;    
        
   return 0;
}  
