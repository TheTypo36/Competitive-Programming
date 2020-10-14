#include <bits/stdc++.h>
using namespace std;


int findMaxSquareWithAllZeros(int **sq, int n , int m)
{
	int dp[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(i==0 || j == 0)
			{
				if(sq[i][j] == 0){
					dp[i][j] = 1;
				}else{
					dp[i][j] = 0;
				}
			}
		}
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			if(sq[i][j] = 0)
			{
				dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
			}else{
				dp[i][j] = 0;
			}
		}
	}
	int ans = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			ans = max(dp[i][j],ans);
		}
	}
	return ans;
}
int main(){
	int n, m;
	cin >> n >> m;
	int **sq = new int*[n];
	for (int i = 0; i < m; ++i)
	{
		sq[i] = new int[m];
		for (int j = 0; j < n; ++j)
		{
			cin >> sq[i][j];
		}
	}
	cout << findMaxSquareWithAllZeros(sq, n, m) << endl;
}