#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll MinDiff(ll* input, ll n, ll k){
	sort(input, input+n);

	ll big = input[n-1] - k;
	ll small = input[0] + k;
	if(small > big){
		ll t = big;
		big =small;
		small = t;
	}
	for(ll i = 1; i < n - 1; i++){
		ll sub = input[i] - k;
		ll add = input[i] + k;
		if(sub>=small ||add <=big){
			continue;
		}
		if(big - sub <= add - small){
			small = sub;
		}else{
			big = add;
		}
	}
	ll diff1 = input[n-1] - input[0];
	ll diff2 = big - small;
	return min(diff2,diff1);
}
int main(){
	ll n;
	cin >> n;
	ll k;
	cin >> k;
	ll* input = new ll[n];
	for (ll i = 0; i < n; ++i)
	{
		cin >> input[i];
	}
	cout << MinDiff(input,n,k) << endl;
}