#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    int n, m;
    cin >> n >> m;
    ll *input = new ll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input, input + n);
    queue<ll> pq;

    int input_it = n - 1;
    int j = 0;
    while(m--){
        int q;
        cin >> q;
        ll ans=0 ;
        for(;j<q; j++){
            if (input_it >= 0 && (pq.empty() || (input[input_it] >= pq.front())))
            {
                ans = input[input_it];
                input_it--;
            }
            else
            {
                ans = pq.front();
                pq.pop();
            }
           
                pq.push(ans / 2);
   
        
        }
        cout << ans << endl;
    }
    return 0;
}