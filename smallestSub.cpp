#include <bits/stdc++.h>
using namespace std;

// int solve(string s, string a){
// 	int n = s.length();
// 	int m = a.length();
// 	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
// 	for (int i = 0; i < n + 1; ++i)
// 	{
// 		for(int j = 0 ; j < m + 1; j++)
// 		{
// 			if(j == 0){
// 				dp[i][j] = 0;
// 			}

// 			if(i == 0)
// 			{
// 				dp[i][j] = INT_MAX-10;
// 			}
			
// 		}
// 	}
// 	for (int i = 1; i < n + 1; ++i)
// 	{
// 		for (int j = 1; j < m + 1 ; ++j)
// 		{
// 			int skip = 0;
// 			for (int k = 0; k < j + 1; ++k)
// 			{
// 				if(k == j){

// 					skip = k;
// 					break; 
// 				}
// 				if(s[i-1] == a[k]){
// 					skip = k;
// 					break;
// 				}
// 			}
// 			if(skip == j){
// 				dp[i][j] = 1;
// 			}else{

// 			int option1 = dp[i-1][j];
// 			int option2 = 1 + dp[i-1][j-skip+1];
// 			dp[i][j] = min(option2,option1);
// 			}
// 		}
// 	}
// 	return dp[n][m];
// }
int helper(string s, string a,int n, int m, int** dp){
 	if(m == 0){
 		return 1;
 	}   
 	if(n <= 0)
 	{
 		return INT_MAX-10; 
 	}
 	if(dp[n][m] != -1){
 		return dp[n][m];
 	}
 	int option =helper(s.substr(1),a,n-1,m,dp);
 	int skip = 0;
 	for (int i = 0; i < a.length()+1; ++i)
 	{
        if(i==a.size()){
            skip=i;
            break;
        }
 		if(s[0] == a[i]){
 			skip = i;
 			break;
 		}
 	}
 	if(skip==a.length()){
 		return 1;
 	}
 	int option2 = 1+helper(s.substr(1),a.substr(skip+1),n-1,m-skip-1,dp);
 	return dp[n][m] = min(option2,option);
}
int solve(string s, string a){
	int n = s.length();
	int m = a.length();
	int** dp = new int*[n+1];
	for (int i = 0; i < n + 1; ++i)
	{
		dp[i] = new int[m+1];
		for (int j = 0; j < m+1; ++j)
		{
			dp[i][j] = -1;
		}
	}
	return helper(s,a,n,m,dp);
}
int main()
{
	string S,V;
	cin>>S>>V;
	cout<<solve(S,V)<<endl;
	return 0;
}