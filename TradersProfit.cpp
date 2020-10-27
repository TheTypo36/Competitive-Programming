#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int MaximumProfit_recur(int* prices, int n, int k, int ongoing, int *** dp)
{
	if(k == 0){
		return 0;
	}
	if(n == 0){
		return 0;
	}
	if(dp[n][k][ongoing] != -1){
		return dp[n][k][ongoing];
	}

	int option1 = MaximumProfit_recur(prices + 1, n - 1, k, ongoing,dp);
	int option2 = 0;
	if(ongoing){
		option2 = MaximumProfit_recur(prices+1,n-1,k-1,0,dp) + prices[0];
	}else{
		if(k>0){

		option2 = MaximumProfit_recur(prices + 1, n - 1, k  , 1,dp) - prices[0];
		}
	}
	dp[n][k][ongoing] = max(option1,option2);
	//cout << dp[n][k] << endl;
	return max(option1,option2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		int n;
		int k;
		cin >> k;
		cin >> n;
		int * prices = new int[n];
		for(int i = 0 ; i < n; i++)
		{
			cin >> prices[i];
		}
		int*** dp = new int**[n+1];
		for (int i = 0; i < n+1; ++i)
			{
				dp[i] = new int*[k+1];
				for (int j = 0; j < k+1; ++j)
				{
					dp[i][j] = new int[2];
					for (int p = 0; p < 2; ++p)
					{
						/* code */
					dp[i][j][p] = -1;
					}
				}
			}
		cout << MaximumProfit_recur(prices, n, k, 0,dp) << endl;
				
		
	}
	return 0;
}