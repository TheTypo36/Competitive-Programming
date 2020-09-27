#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll LargestMinDis(int *position, int stalls, int cows)
{


    sort(position,position+stalls);
    ll start = 0;
    ll end = position[stalls-1] - position[0];
    ll ans = -1;
    while (start <= end)
    {
        ll dis = (start+end)/2;
        ll cowPlaced = cows - 1;
        ll i = 1;
        ll prev = position[0];
        while (i < stalls&&cowPlaced>0)
        {
            if(position[i] - prev >= dis){
                prev = position[i];
                cowPlaced--;
            }
            i++;
        }
        if(cowPlaced>0)
        {
            end = dis - 1;
        }else{
            ans = max(ans,dis);
            start = dis + 1;
        }
        
    }
    return ans;
    
}
int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int stalls, cows;
        cin >> stalls >> cows;
        int position[100001];
        for (int i = 0; i < stalls; i++)
        {
            cin >> position[i];
        }
        cout << LargestMinDis(position, stalls, cows) << endl;
    }

    return 0;
}