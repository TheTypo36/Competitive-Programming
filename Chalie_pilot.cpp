#include <bits/stdc++.h>
using namespace std;
int MinimalCost(int* cap, int* assist, int n, int x, int ** dp)
{
	if(n == 0){
		return 0;
	}
	if(dp[n][x] != -1){
		return dp[n][x] ;
	}
	//cout << x << endl;
	int ans = 0;
	if(x==0){
		ans = assist[0] + MinimalCost(cap + 1, assist + 1, n - 1, 1,dp);
	}
	else if(x == n)
	{
		ans = cap[0] + MinimalCost(cap+1 , assist + 1, n -1 , x - 1,dp);
	}else{
		int option = assist[0] + MinimalCost(cap + 1, assist + 1, n - 1, x + 1,dp);
		int option2 = cap[0] + MinimalCost(cap + 1, assist + 1, n - 1 , x - 1,dp);
		ans = min(option2, option);
	}
	dp[n][x] = ans;
	return ans;
}

int main(){
	int n;
	cin >> n;
	int* cap = new int[n];
	int* assist = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> cap[i] >> assist[i] ;
	}
	int** dp = new int*[n + 1] ;
	for (int i = 0; i < n + 1; ++i)
	{
		
		dp[i] = new int[n + 1];
		for (int j = 0; j < n + 1; ++j)
		{
			dp[i][j] = -1;
		}
	}
	cout << MinimalCost(cap, assist, n, 0, dp) << endl;
	
	 for(int i=0; i<=n; i++)
    {
        delete[]dp[i];
    }
    delete[]dp;
}