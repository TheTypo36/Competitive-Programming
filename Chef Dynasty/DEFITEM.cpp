#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n,q;
		cin >> n >> q;
		ll* arr = new ll[n];
		for(int i = 0 ;i < n; i++){
			cin >>arr[i];
		} 
		vector<ll> prefix_sum(n,0);
		ll sum = 0;
		for(int i = 0; i < n; i++){
			sum += arr[i];	
			prefix_sum[i] = sum;
		}
		vector<ll> Suffix_sum(n,0);
		sum = 0;
		for (int i = n-1; i >=0; i--)
		{

			sum+=arr[i];
			Suffix_sum[i] = sum;
		}
		unordered_map<ll,ll> ans;
		for (int i = 0; i < n; ++i)
		{
			ans[arr[i]] = min(prefix_sum[i],Suffix_sum[i]);
		}
		while(q--){
			ll query;
			cin >> query;
			cout << ans[query] <<"\n";
		}
	}
}