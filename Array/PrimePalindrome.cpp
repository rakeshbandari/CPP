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
int reverse(int n)
{
    int ret = 0;
    int tmp = n;
    while(tmp)
    {
        int rem = tmp%10;
        ret = ret*10 + rem;
        tmp /= 10;
    }
    return ret;
}
int digit_count(int n)
{
    int ret = 0;
    while(n)
    {
        n/=10;
        ret++;
    }
    return ret;
}
int primePalindrome(int N) {
    while(true)
    {
        if(N>=8 && N<=11)
            return 11;
        if(reverse(N)==N && is_prime(N))
            return N;
        int cnt = digit_count(N);
        if(cnt&1)
            N++;
        else
            N = pow(10,cnt)+1;
    }
    return N;
}
int main()
{
   return 0;
}    
