#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int count = 0;
    int i = 0, j = 1;
    while (i < n && j < n)
    {
        if (i == j)
        {
            j = i + 1;
        }
        if (arr[j] - arr[i] >= k)
        {
            count += (n - j);
            i++;
        }
        else
        {
            j++;
        }
    }

    cout << count << endl;
}