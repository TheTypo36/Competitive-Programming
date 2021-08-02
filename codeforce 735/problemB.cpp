#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define F first
#define S second
typedef long long ll;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	ll testcases;
	cin >> testcases;
	while(testcases--)
	{
		ll n;
		cin >> n;
		ll k;
		cin >> k;
		vector<ll> v(n,0);
		for(ll i = 0 ;i < n; i++){
			cin >> v[i];
		}
		ll maxAns = INT_MIN;
		for(ll i = 0 ;i < n; i++){
			for(ll j = i + 1; j < n; j++){
				ll ij = (i+1)*(j+1);
				ll aOrb = v[i]|v[j];
				ll currMax = ij - k * aOrb;
				maxAns = max(currMax,maxAns);
			}
		}
		cout << maxAns << endl;
	}
	return 0;
}