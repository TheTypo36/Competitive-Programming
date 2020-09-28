#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int n, x;
        cin >> n >> x;
       int s = 2, k = 1;
       while(s<n)
       {
           s+=x;
           k++;
       }
       cout << k << endl;
    }
}