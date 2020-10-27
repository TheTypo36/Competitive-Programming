#include <bits/stdc++.h>
using namespace std;

int total_min_fare(int** strg,int row, int col, int n, int m,int ** dp)
{
	
	if(row == n){
		return 0;
	}
	if(dp[row][col] != -1)
	{
		return dp[row][col];
	}

	int option2 = strg[row][col]+total_min_fare(strg,row+1,col,n,m,dp);
	int option1 = INT_MAX;
	if(col+1 < m){
		option1 = strg[row][col]+total_min_fare(strg,row+1,col+1,n,m,dp);
	}
	int option3 = INT_MAX;
	if(col - 1 >=0){
	 	option3 = strg[row][col]+total_min_fare(strg,row+1,col-1,n,m,dp);
	}
	return dp[row][col] = min(option2,min(option3,option1));
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	int m; 
	cin >> m;
	int** strg = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		strg[i] = new int[m];
		for (int j = 0; j < m; ++j)
		{
			cin >> strg[i][j];
		}
	}
	int min_ans = INT_MAX;
	int** dp = new int*[n+1];
		for (int i = 0; i < n+1; ++i)
		{
			dp[i] = new int[m+1];
			
		}
	for (int i = 0; i < m; ++i)
	{
		
		for (int i = 0; i < n+1; ++i)
		{
			for (int j = 0; j < m+1; ++j)
			{
				dp[i][j] = -1;				
			}
		}
		min_ans = min(min_ans,total_min_fare(strg,0,i,n,m,dp));
	}
	cout << min_ans << endl;
	  for(int i=0; i<n+1; i++)
    {
        delete[]dp[i];
    }
    delete[]dp;
	return 0;
}