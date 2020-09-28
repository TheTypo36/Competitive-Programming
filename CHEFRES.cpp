#include <bits/stdc++.h>
using namespace std;

int main()
{
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
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
        sort(timing.begin(), timing.end());
        for (int i = 0; i < m; i++)
        {
            int prsn;
            cin >> prsn;
            int position = lower_bound(timing.begin(), timing.end(), make_pair(prsn, 0)) - timing.begin();
            if (position == 0)
            {
                int ans = timing[0].first - prsn;
                cout << ans << endl;
            }
            else
            {
                int ans = -1;
                
                    if (timing[position-1].second > prsn)
                    {
                        ans = 0;
                    }
                
                else if (position < timing.size())
                {
                    ans = timing[position].first - prsn;
                }
                cout << ans << endl;
            }
        }
    }
}