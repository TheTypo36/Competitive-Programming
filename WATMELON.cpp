#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {

        int n;
        cin >> n;
        bool c = true;
        int *input = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
            sum += input[i];
        }
        if (sum >= 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}