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
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		int n;
		cin >> n;
		vector<ll> v(n,0);
		unordered_map<ll,ll> freq;
		for(int i = 0 ; i < n; i++){
			cin >> v[i];
			freq[v[i]]++;
		}

		// ll maxi = 0;
		// ll x = 0;
		// for(unordered_map<ll,ll>::iterator it=freq.begin(); it != freq.end(); it++){
		// 	ll total = it->F * it->S;
		// 	if(maxi<total){
		// 		maxi = total;
		// 		x = it->S;
		// 	}
		// }

			ll bitwiseOR = INT_MAX;
			ll x = 0;
		for(int j = 0 ; j < n; j++){

			ll currx = v[j];
			ll currbw = 0;
			for (int i = 0; i < n; ++i)
			{
				currbw |= (v[i]^x);
			}

			if(bitwiseOR > currbw){
				bitwiseOR = currbw;
				x = currx;
			}

			
		}
		cout << x << " "<< bitwiseOR << endl;
		
	}
	return 0;
}