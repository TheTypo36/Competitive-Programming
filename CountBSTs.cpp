#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
/*
int countBST(int n)
{
	int* strg = new int[n];
	strg[0] = 1;
	strg[1] = 1;
	for (int i = 2; i <=n; ++i)
	{
		int sum = 0;
		for (int j = 1; j <= i; ++j)
		{
			sum = (sum%MOD + (strg[j-1]%MOD * strg[i-j]%MOD)%MOD)%MOD;
		}
		strg[i] = sum;
	}
	int ans = strg[n];
	delete []strg;
	return ans;
}

*/
int countBST(int n)
{
	long long* strg = new long long[n+1];
	strg[0] = 1;
	strg[1] = 1;
	for (long long i = 2; i <=n; ++i)
	{
		long long sum = 0;
		for (int j = 1; j <= i; ++j)
		{
			sum = (sum%MOD + (strg[j-1]%MOD * strg[i-j]%MOD)%MOD)%MOD;
		}
		strg[i] = sum;
	}
	long long ans = strg[n];
	delete []strg;
	return ans%MOD;
}

int countBst(int n)
{
	if(n == 1 || n == 0)
	{
		return 1;
	}
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		sum = (sum%MOD+(countBst(i-1)%MOD * countBst(n - i)%MOD)%MOD)%MOD;
	}
	return sum;
}
int main(){
	int n;
	cin >> n;
	cout << countBst(n) << endl;
	cout << countBST(n) << endl;
	//cout << count_trees(n) << endl;
}