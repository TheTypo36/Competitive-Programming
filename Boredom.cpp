#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> input){
	vector<int> frq(10001, 0);
	for (int i = 0; i < n; ++i)
	{
		frq[input[i]]++;
	}
	vector<int> dp(1001);
	dp[0] = 0;
	dp[1] = frq[1];
	for (int i = 2; i < 1001; ++i)
	{
		dp[i] = max((dp[i-2]+(frq[i]*i)),dp[i-1]);
	}
	return dp[1000];
}
int solve2(int n, vector<int> &input)
{
	sort(input.begin(),input.end(), greater<int>());
	unordered_map<int, int> frq;
	int sum = input[0];
	frq[input[0] - 1]++;
	frq[input[0] + 1]++;
	for (int i = 1; i < n; ++i)
	{
		if(frq[input[i]] == 0){
			cout <<i<< " " << input[i] << endl;
			sum +=input[i];
			frq[input[i] - 1]++;
			frq[input[i] + 1]++;
		}else{
			frq[input[i]]--;
		}
	}

	return sum;
}
int main(){
	int n;
	cin >> n;
	vector<int> input(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}
	cout << solve(n, input) << endl;
}