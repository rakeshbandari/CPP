#include "Tree.cpp"

int catalan_number(int n) 
{
	int catalan[n+1];
	catalan[0] = catalan[1] = 1;
	
	for(int i=2; i <= n; i++){
		catalan[i] = 0;
		for(int j=0; j<i; j++)
			catalan[i] += catalan[j] * catalan[i-j-1];
	}
  return catalan[n];
}

unsigned long int catalan(unsigned int n)
{
    // Base case
    if (n <= 1)
        return 1;
 
    // catalan(n) is sum of
    // catalan(i)*catalan(n-i-1)
    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);
 
    return res;
}

int main()
{
  int n = 3;
  
  cout << catalan(n); 
  cout << catalan_number(n);    
  return 0;
}
