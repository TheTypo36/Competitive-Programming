#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll largestMinDis(ll *input, int n, int tCows)
{
    sort(input, input + n);
    ll start = 0;
    ll end = input[0]-input[n - 1];
    ll max_dis = 0;
    while (start < end)
    {
        ll dis = start+((end - start) / 2);
        
        ll cow = tCows - 1;
        ll i = 1;
        ll prev = input[0];
        while (i < n && cow--)
        {
            if (input[i] - prev >= dis)
            {
                prev = input[i];
                i++;
            }
            else
            {
                i++;
            }
        }
        if(cow>0){
            end = dis -1;
        }else{
            max_dis=max(max_dis,dis);
            start = dis + 1;
        }
    }
    return max_dis;
}
int main()
{

    int testcases;
    cin >> testcases;
    while (testcases--)
    {

        int n;
        cin >> n;
        int numCow;
        cin >> numCow;
        ll input[100001];
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        cout << largestMinDis(input, n, numCow) << endl;
    }
}