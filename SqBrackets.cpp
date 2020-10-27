#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int NumberOf(int total, bool* curr_ind, int opening,int closing, int ** dp)
{
	if(opening > total || closing > total){
		return 0;
	}
	if(opening == total && closing == total){
		return 1;
	}
	if(dp[opening][closing]!=-1){
		return dp[opening][closing];
	}
	int ans = 0;
	if(opening == closing || (curr_ind[closing + opening] == true))
	{
		ans = NumberOf(total,curr_ind,opening+1,closing, dp);
	}else if(opening == total){
		ans = NumberOf(total ,curr_ind, opening, closing + 1, dp);
	}else{
		ans = NumberOf(total,curr_ind,opening+1,closing,dp) + NumberOf(total ,curr_ind, opening, closing + 1,dp);
	}
	return dp[opening][closing] = ans;
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
		cin >> n;
		int k ; 
		cin >> k;
		int *input =new int[k];
		for (int i = 0; i < k; ++i)
		{
				cin >> input[i];
		}
		bool *curr_ind = new bool[2*n];
		for (int i = 0; i < k; ++i)
		{
			curr_ind[input[i] - 1] = true;
		}
		int** dp = new int*[n + 1];
		for (int i = 0; i < n+1; ++i)
		{
			dp[i] = new int[n+1];
			for (int j = 0; j < n+1; ++j)
			{
				dp[i][j] = -1;
			}
		}
		cout << NumberOf(n,curr_ind,0,0,dp) << endl;
	}
	return 0;
}