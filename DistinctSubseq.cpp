#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int MOD = pow(10,9) + 7;
ll getDistinctSS(string s)
{
	ll n = s.length();
	ll* dp = new ll[n + 1];
	unordered_map<char,int> lo;
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		char ch = s[i-1];
		dp[i] = (2*dp[i-1])%MOD;
		if(lo.count(ch)>0){
			ll j = lo[ch];
			dp[i] = (dp[i] - dp[j-1])%MOD;
		}
		lo[ch] = i;
	}
	ll ans = dp[n]%MOD;
	return ans;
}
int main()
{
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		string s;
		cin >> s;
		int ans = getDistinctSS(s);
		cout << ans << endl;
	}
	return 0;
}