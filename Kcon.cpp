#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll kadanes_algo(int *input, int n)
{
    ll best_so_far = INT_MIN;
    ll curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += input[i];
        if (best_so_far < curr_sum)
        {
            best_so_far = curr_sum;
        }
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return best_so_far;
}
ll kcon(int *input, int n, int k)
{
    ll kadanes = kadanes_algo(input, n);
    if (k == 1)
    {
        return kadanes;
    }
    ll best_preffix_sum = INT_MIN;
    ll curr_preffix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_preffix_sum += input[i];
        if (curr_preffix_sum > best_preffix_sum)
            best_preffix_sum = curr_preffix_sum;
    }
    ll total_sum = curr_preffix_sum;
    ll best_suffix_sum = INT_MIN;
    ll curr_suffix_sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        curr_suffix_sum += input[i];
        if (curr_suffix_sum > best_suffix_sum)
        {
            best_suffix_sum = curr_suffix_sum;
        }
    }
    ll ans = 0;
    if (total_sum < 0)
    {
        ans = max(best_preffix_sum + best_suffix_sum, kadanes);
    }
    else
    {
        ans = max(best_suffix_sum + best_preffix_sum + ((k - 2) * total_sum), kadanes);
    }
    return ans;
}
int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        int *input = new int[n];
        for (int i = 0; i < n; i++)
            cin >> input[i];

        
        cout << kcon(input, n, k) << endl;
    }
}