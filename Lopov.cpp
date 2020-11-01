#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class jew{
	public:
		int mass;
		int value;
};
bool compare(jew a, jew b){
	return a.value> b.value;
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	ll n;
	cin >> n;
	ll k ;
	cin >> k;
	jew* jeweries = new jew[n];
	for (ll i = 0; i <n ; ++i)
	{
		cin >> jeweries[i].mass >> jeweries[i].value;

	}
	sort(jeweries,jeweries + n, compare);
	multiset<ll> bags;
	for (ll i = 0; i < k; ++i)
	{
		ll input;
		cin >> input;
		bags.insert(input);
	}
	ll ans = 0;
	for ( ll i = 0; i < n; ++i)
	{
		if(bags.lower_bound(jeweries[i].mass)!=bags.end()){
			ans += jeweries[i].value;
			bags.erase(bags.lower_bound(jeweries[i].mass));
		}
	}
	cout << ans << endl;
}