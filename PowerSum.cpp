#include <bits/stdc++.h>
using namespace std;
int powerSum(int x, int n, int sum)
{
     if (x < 0)
    {
        return 0;
    }
    if (x ==0)
    {

        return 1;
    }

     return powerSum(x-pow(sum,n), n,sum+1)+powerSum(x,n,sum+1) ;
 
}
int main()
{

    int n, x;
    cin >> x >> n;
    string s;
    cout << powerSum(x, n, 1) << endl;
}