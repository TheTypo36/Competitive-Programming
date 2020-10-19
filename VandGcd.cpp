#include <bits/stdc++.h>
using namespace std;

int MOD = (int) pow(10,9) + 7;
int LenSubSeq(int * arr, int n)
{
	vector<vector<int>> dp(n,vector<int>(101, 0));
	dp[0][arr[0]] =1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if(arr[i] > arr[j]){
				for (int g = 1; g <=100; ++g)
				{
					int ng = __gcd(arr[i],g);
					dp[i][ng] = (dp[i][ng]+dp[j][g])%MOD;
				}
			}
		}
		dp[i][arr[i]]++;
	}
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum = (sum+dp[i][1])%MOD ;
	}
	return sum;
}
int main(){
	int n;
	cin >> n;
	int * input = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}
	cout << LenSubSeq(input , n) << endl;
}