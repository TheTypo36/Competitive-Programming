#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll merge(ll *input, ll left, ll mid, ll right)
{
    ll inverse = 0;
    ll i = left;
    ll j = mid;
    ll temp[right - left + 1];
    ll k = 0;
    while (i < mid && j <= right)
    {
        if (input[i] > input[j])
        {
            temp[k++] = input[j++];
            inverse += (mid - i);

        }
        else
        {
            temp[k++] = input[i++];
        }
    }
    while (i < mid)
    {
        temp[k++] = input[i++];
    }
    while (j <= right)
    {
        temp[k++] = input[j++];
    }
    for (int i = left, k = 0; i <= right; i++, k++)
    {
        input[i] = temp[k];
    }

    return inverse;
}

ll merge_sort(ll A[], ll left, ll right)
{
    ll total_inversion = 0;
    if (left < right)
    {
        ll mid = (left + right) / 2;
        ll leftans = merge_sort(A, left, mid);
        ll rightans = merge_sort(A, mid + 1, right);
        ll curr_inversion = merge(A, left, mid + 1, right);
        return leftans + rightans + curr_inversion;
    }
    return total_inversion;
}
int main()
{

    ll n;
    cin >> n;
    ll *input = new ll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    cout << merge_sort(input, 0, n - 1) << endl;

    return 0;
}