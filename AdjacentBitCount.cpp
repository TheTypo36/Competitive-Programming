#include <bits/stdc++.h>
using namespace std;
int mod = (int) pow(10, 9) + 7;

int NumOf(int n , int k, int first, int*** dp)
{
	if(k <0){
		return 0;
	}
	if( n == 0)
	{
		if( k == 0)
			return 1;
		else
			return 0;
	}
	if(dp[n][k][first] !=-1){
		return dp[n][k][first];
	}

	int ans = 0;
	if(first == 0){
		ans = (NumOf(n-1,k,1,dp)%mod + NumOf(n-1,k,0,dp)%mod)%mod;
	}else{
		ans = (NumOf(n-1,k-1,1,dp)%mod + NumOf(n-1,k,0,dp)%mod)%mod;
	}
	return dp[n][k][first] = ans;
}
int main(){
	int n;
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		int no, n, k;
		cin >> no >> n >> k;
		//vector<vector<vector<int>>>dp(n+1,vector<int>(k+1,vector<int>(2,-1)));
		int*** dp = new int**[n+1];
		for (int i = 0; i <= n; ++i)
		{
			dp[i] = new int*[k+1];
			for (int j = 0; j <= k ; ++j)
			{
				dp[i][j] = new int[2];
				for (int k = 0; k < 2; ++k)
				{
					dp[i][j][k] = -1;
				}
			}
		}
		cout << no <<" "<< NumOf(n, k, 0, dp)<< endl;
	}
}