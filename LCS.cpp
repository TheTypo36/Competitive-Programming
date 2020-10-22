#include <bits/stdc++.h>
using namespace std;
int lcs_dp(string a, string b)
{
	vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));
	for (int i = 1; i <= a.length(); ++i)
	{
		for (int j = 1; j <= b.length(); ++j)
		{
			if(a[i-1] == b[j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
			}
		}
	}
	return dp[a.length()][b.length()];
}
int recur_lcs(string a, string b)
{
	if(a.length() == 0 || b.length() == 0)
	{
		return 0;
	}
	if(a[0] == b[0])
	{
		return 1 + recur_lcs(a.substr(1), b.substr(1));
	}
	int f1 =  recur_lcs(a.substr(1), b);
	int f2 =  recur_lcs(a, b.substr(1));
	return max(f1,f2);
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	string a,b;
	cin >> a >> b;
	cout << lcs_dp(a,b) << endl;
	cout << recur_lcs(a,b) << endl;
}