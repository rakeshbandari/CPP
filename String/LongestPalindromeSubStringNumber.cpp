#include <bits/stdc++.h>
using namespace std;

int lps(char *seq, int i, int j)
{
    if (i == j)
        return 1;

    if (seq[i] == seq[j] && i + 1 == j)
        return 2;

    if (seq[i] == seq[j])
        return lps (seq, i+1, j-1) + 2;

    return max( lps(seq, i, j-1), lps(seq, i+1, j) );
}
 
int main()
{
    char str[] = "forgeeksskeegfor";
    cout << "\nLength is: "
         << lps(str, 0, strlen(str)-1)
         << endl;
    return 0;
}
 
