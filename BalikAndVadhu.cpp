#include <bits/stdc++.h>
using namespace std;
int HappinessDp(string a, string b, int k){
	int m = a.length();
	int n = b.length();
	int*** dp = new int**[m+1];
	for (int i = 0; i <= m+1; ++i)
	{
		dp[i] = new int*[n+1];
		for (int j = 0; j <= n; ++j)
		{
			dp[i][j] = new int[k+1];
		}
	}
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			dp[i][j][0] = 0;
		}
	}
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			for (int p = 1; p <= k; ++p)
			{
				if(i== 0|| j == 0)
				{
					dp[i][j][p] = INT_MIN;
				}
			}
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int p = 1; p <= k; ++p)
			{
				if(a[i-1] == b[j-1]){
					int ascii = b[j-1];
					dp[i][j][p] = max(ascii+dp[i-1][j-1][p-1],max(dp[i-1][j][p],dp[i][j-1][p]));
				}else{
					dp[i][j][p] = max(dp[i-1][j][p],dp[i][j-1][p]);
				}
			}
		}
	}
	return dp[m][n][k];
}
int Happiness(string a, string b, int k,int*** dp)
{

	if(k == 0){
		return 0;
	}
	if(a.length() == 0 || b.length() == 0 ){
		return INT_MIN;
	}
	if(dp[a.length()][b.length()][k] != -1){
		return dp[a.length()][b.length()][k];
	}
    int ans;
	if(a[0] == b[0])
	{
		int ascii = a[0];
		int f1 = ascii + Happiness(a.substr(1),b.substr(1),k-1,dp);
		
		int f2 = Happiness(a.substr(1),b,k,dp);
		int f3 = Happiness(a, b.substr(1), k,dp);
		ans = max(f1,max(f2,f3));
	}else{
		int f1 = Happiness(a.substr(1),b,k,dp);
		int f2 = Happiness(a,b.substr(1),k,dp);
		ans = max(f1,f2);
	}
    dp[a.length()][b.length()][k] = ans;
    return ans;


}

int main(){
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		string a;
		string b;

		cin >> a >> b;
		int k;
		cin >> k ;
		int ans;
		    int ***dp=new int**[101];
        for(int i=0; i<101; i++)
        {
            dp[i]=new int *[101];
            for(int j=0; j<101; j++)
            {
                dp[i][j]=new int [101];
                for(int k=0; k<101; k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
		 ans = HappinessDp(a,b,k);
		if(ans <0)
			cout << 0 << endl;
		else
		cout << ans << endl;
		//cout << HappinessDp(a,b,k) << endl;
	}
}