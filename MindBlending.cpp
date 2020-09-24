#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void product(int *input, int n)
{
    int p[n];
    int lp = 1;
    for (int i = 0; i < n; i++)
    {
        p[i] = lp;
        lp = input[i] * lp;
    }
    int rp = 1;
    for (int i = n-1; i >= 0; i--)
    {
        p[i] = p[i] * rp;
        rp = rp * input[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }

    cout << endl;
}
int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        product(arr, n);
    }
}