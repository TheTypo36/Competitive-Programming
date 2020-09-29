#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 ll merge(ll *input, ll left, ll mid, ll right)
{
    ll k = 0;
    ll temp[right - left + 1];
    ll i = left;
    ll j = mid;
    ll sum = 0;
    while (i < mid && j <= right)
    {
        if (input[i] < input[j])
        {
            sum += (input[i] * (right - j + 1));
            temp[k++] = input[i++];
        }
        else
        {
            temp[k++] = input[j++];
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
    for (ll i = left, p = 0; i <= right; i++, p++)
    {
        input[i] = temp[p];
    }
    return sum;
}
ll merge_sort(ll *input, ll left, ll right)
{
    ll sum = 0;
    if (left < right)
    {
        ll mid = (left + right) / 2;
        ll leftsum = merge_sort(input, left, mid);
        ll rightsum = merge_sort(input, mid + 1, right);
        ll mergeAns = merge(input, left, mid + 1, right);
        return leftsum + rightsum + mergeAns;
    }
    return sum;
}
int main()
{

    ll testcases;
    cin >> testcases;
    while (testcases--)
    {
        ll n;
        cin >> n;
        ll *input = new ll[n];
        for (ll i = 0; i < n; ++i)
        {
            cin >> input[i];
        }
        cout << merge_sort(input, 0, n - 1) << endl;
    }
    return 0;
}