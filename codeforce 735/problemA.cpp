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
		ll n;
		cin >> n;
		std::vector<ll> v(n,0);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}

		ll maxValue = INT_MIN;
		for (ll i = 0; i < n-1; ++i)
		{
			ll maxPart = max(v[i],v[i+1]);
			ll minPart = min(v[i],v[i+1]);

			ll currMaxValue = (maxPart * minPart);

			maxValue = max(maxValue, currMaxValue);

			//cout << "minPart " << minPart << " maxPart " << maxPart << " currMaxValue " << currMaxValue << " maxValue " << maxValue << endl;  


		}
		cout << maxValue<< endl;
	}
	return 0;
}