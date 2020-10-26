#include <bits/stdc++.h>
using namespace std;
bool subsetSum(int* val, int n, int sum){
	bool* row1 = new bool[n+1];
	bool* row2 = new bool[n+1];
	for (int i = 0; i < sum+1; ++i)
	{
		row1[i] = false;
	}

	row1[0] = true;
	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < sum+1; ++j)
		{
			if(val[i-1] > j){
				row2[j] = row1[j];
			}else{
				bool option1 = row1[j];
				bool option2 = row1[j-val[i-1]];
				row2[j] = (option2||option1);
			}
			for (int j = 0; j < sum+1; ++j)
			{
				row1[i] = row2[i];
			}
		}
	}
	bool ans = row2[sum];
	delete [] row1;
	delete [] row2;
	return ans;
}
bool subsetSumDp(int* val, int n, int sum )
{
	bool** dp = new bool*[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i] = new bool[sum + 1];
		for (int j = 0; j < sum+1; ++j)
		{
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < sum+1; ++j)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
		}
	}
	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < sum+1; ++j)
		{
			if(val[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				bool option1 = dp[i-1][j-1];
				bool option2 = dp[i-1][j-val[i-1]];
				dp[i][j] = (option2||option1);
			}
		}
	}
	return dp[n][sum];
}
bool subsetSumMemoisation(int * val, int n, int sum, int ** dp)
{
	if(sum == 0)
	{
		return true;
	}
	if(n == 0){
		return false;
	}
	if(dp[n][sum] != -1){
		return dp[n][sum];
	}
	bool ans ;
	if(val[0] > sum){
		ans = subsetSumMemoisation(val+1 , n - 1, sum, dp);
	}else{
		bool option1 = subsetSumMemoisation(val + 1, n - 1, sum, dp);
		bool option2 = subsetSumMemoisation(val + 1, n - 1, sum - val[0], dp);
		ans = (option2||option1);
	}
	return dp[n][sum] = ans;
}
int main(){
	int n;
	cin >> n;
	int * val = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> val[i] ;
	}
	int sum ;
	cin >> sum;
	bool** dp = new bool*[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i] = new bool[sum + 1];
		for (int j = 0; j < sum+1; ++j)
		{
			dp[i][j] = -1;
		}
	}
	//bool ans = subsetSum(val, n, sum, dp) ;
	bool ans = subsetSum(val,n,sum);
	if(ans)
	{
		cout << "Yes" << endl;
	}else
	{
		cout << "No" << endl;
	}
}
