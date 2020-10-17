#include <bits/stdc++.h>
using namespace std;
int minCount(int n)
{
	vector<int> dp(n+1, INT_MAX);
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <=n; i++){
		for (int j = 1; j*j <=i; ++j)
		{
			int prev = 1+dp[i-(j*j)];
			dp[i] = min(prev,dp[i]);
		}
	}
	return dp[n];
}
int minCount2(int n){
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	int ans = INT_MAX;
	for (int i = 1; i*i <= n ; ++i)
	{
		int recur = 1 + minCount2(n-(i*i));
		ans = min(ans,recur);
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n) << endl;
	cout << minCount2(n) << endl;
}