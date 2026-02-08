#include<bits/stdc++.h>
using namespace std;

unsigned long int fact(int n)
{
	unsigned long int f = 1;
	
	if(n == 1)
	  return f;
	
	f = n*fact(n-1);
	
	return f;
}


void factorial(int n, unsigned long int &f)
{
	for(f=1; n>1; n--){
		f *= n;		
	}	
}
int main()
{
	int a = 5;
	unsigned long int b = 0; 
	
	factorial(a, b);
	cout << "factorial : " << b << endl;
		
	b = fact(a);
	cout << "factorial : " << b;
	
	return 0;
}
