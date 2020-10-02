#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void test_case(ll * input, ll n,ll k ){
	
	ll sum = 0;
	for (ll i = 0; i < n; ++i)
	{
		sum+=input[i];
	}
	ll var = 0;
	for(ll i = 0; i < n; ++i)
		{
			var+=input[i];
			if(var < k){
				cout << i + 1 << endl;
				return;
			}
			var -=k;
		}
		ll ans = 0;
		ans = (sum/k) +1;
		cout << ans << endl;
		return;
}


int main()
{
	ll testcases;
	cin >> testcases;
	while(testcases--)
	{
		ll n, k;
		cin >> n >> k;
		ll* input = new ll[n];
		for (ll i = 0; i < n; ++i)
		{
			cin >> input[i] ;
		}
		test_case(input, n, k);
	}
	return 0;
}