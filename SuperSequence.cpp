#include <bits/stdc++.h>
using namespace std;
int lcs(char str1[], char str2[], int n, int m){
	vector<vector<int>> dp(n+1,vector<int>(m+1, 0));
	for (int i = 1; i < n + 1 ; ++i)
	{
		for (int j = 1; j < m+1; ++j)
		{
			if(str1[i-1] == str2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				int option = dp[i-1][j];
				int option2 = dp[i][j-1];
				int option3 = dp[i-1][j-1];
				dp[i][j] = max(option,max(option2,option3));
			}
		
		}

	}
	int ans = dp[n][m];
	
	return ans;
}
int smallestSuperSequence(char str1[], int len1, char str2[], int len2) { 
 int ans = (len1 + len2) - lcs(str1,str2,len1,len2);
 return ans;
}
int main()
{
    char str1[50], str2[50];
    cin>>str1;
    cin>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = smallestSuperSequence(str1, len1, str2, len2);
    cout<<min_len;
    return 0;
}
