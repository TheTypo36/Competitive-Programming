#include <bits/stdc++.h>
using namespace std;

void waitingTime(vector<pair<int, int>> timing, int n, int prsn)
{
    if (prsn < timing[0].first)
    {
        cout << timing[0].first - prsn << endl;
        return;
    }
    int start = 0;
    int end = n;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (timing[mid].first == prsn)
        {
            cout << 0 << endl;
            return;
        }
        if (timing[mid].first < prsn && timing[mid].second > prsn)
        {
            cout << 0 << endl;
            return;
        }
        else if (timing[mid].second == prsn)
        {
            cout << timing[mid + 1].first - timing[mid].second << endl;
            return;
        }
        else if (prsn < timing[mid].first)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << -1 << endl;
}
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {

        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> timing(n);
        for (int i = 0; i < n; i++)
        {
            int arr, dep;
            cin >> arr >> dep;
            timing[i].first = arr;
            timing[i].second = dep;
        }
        sort(timing.begin(), timing.end(), compare);
        for (int i = 0; i < m; i++)
        {
            int person;
            cin >> person;
            waitingTime(timing, n, person);
        }
    }
}