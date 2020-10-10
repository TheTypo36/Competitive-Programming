#include <bits/stdc++.h>
using namespace std;
int mod = pow(10, 9) + 7;
int alphaCode_memoization(string s, string print, int *strg)
{
	if (s[0] == '0')
	{
		return 0;
	}
	if (s.length() == 0)
	{
		//cout << print << endl;
		//print = "";
		return 1;
	}
	if(strg[s.length()]!=-1){
		return strg[s.length()];
	}
	char cc = s[0];
	int x = cc - '0';
	char ch = (char)64 + x;
	int ans = 0;
	ans += alphaCode_memoization(s.substr(1), print + ch,strg);
	int ans2 = 0;
	if (s.length() > 1)
	{
		string str = s.substr(0, 2);
		stringstream con(str);
		int x = 0;
		con >> x;
		if (x <= 26)
		{
			char ch2 = (char)(x + 64);
			ans2 += alphaCode_memoization(s.substr(2), print + ch2,strg);
		}
	}
	int finalans = (ans % mod + ans2 % mod) % mod;
	strg[s.length()] = finalans;
	return finalans;
}
int alphaCode_dp_bottomUp(string s){
	int n = s.length();
	int* strg = new int[n+1];
	//seeding

	strg[0] = 1;
	if(s[0]=='0'){
		strg[1]= 0;
	}else{
	strg[1] = 1;
	}
	for (int i = 2; i <= n; ++i)
	{
		strg[i] = 0;
		if(s[i-1]!='0'){
		strg[i]+= strg[i-1]%mod;
		}
		string str = s.substr(i-2,2);
		if(str[0] !='0'){
		stringstream con(str);
		int x = 0;
		con >> x;
		if(x<=26){
		strg[i] +=strg[i-2]%mod;
		}	
		
	}
		
	}
	int output = strg[n];
	delete []strg;
	return output;
}
int main()
{

	string s;
	cin >> s;
	while (s[0] != '0')
	{
		int *strg = new int[s.length()+1];
		for (int i = 0; i <=s.length(); ++i)
		{
			strg[i] = -1;
		}
		int ans = alphaCode_memoization(s, "",strg) % mod;
		int ans2 = alphaCode_dp_bottomUp(s)%mod;
		cout << "memoized ans" << endl;
		cout << ans << endl;
		cout << "DP ans" << endl;
		cout << ans2 << endl;
		cin >> s;
	}
}