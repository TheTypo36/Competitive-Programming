#include <bits/stdc++.h>
using namespace std;
int countWaysToMakeChangeDp(int* denomination, int numDenomination, int value){
	int **strg = new int*[numDenomination+1];
	for (int i = 0; i <= numDenomination; ++i)
	{
		strg[i] = new int[value+1];
	}
	for (int i = 0; i <= numDenomination; ++i)
	{
		strg[i][0]=1;
	}
	for (int i = 0; i <= value ; ++i)
	{
		strg[0][i] = 0;
	} 
	for (int i = 1; i <=numDenomination; ++i)
	{
		for (int j = 1; j <= value; ++j)
		{
			if(j < denomination[i-1]){
				strg[i][j] = strg[i-1][j];
			}else{
				strg[i][j] = strg[i-1][j]+strg[i][j-denomination[i-1]];
			}
		}

	}
	return strg[numDenomination][value];
}
int countWaysToMakeChange(int* denomination, int numDenomination, int value)
{
	if(value == 0){
		return 1;
	}
	if(numDenomination == 0){
		return 0;
	}
	if(value < denomination[0]){
		return countWaysToMakeChange(denomination+1,numDenomination-1,value);
	}

	int ans2 = countWaysToMakeChange(denomination+1,numDenomination-1,value);
	int ans1 = countWaysToMakeChange(denomination,numDenomination, value - denomination[0]);
	int ans = ans1+ans2;
	return ans;
}
int main(){
	int n;
	cin >> n;
	int* coins = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> coins[i];	
	}
	int value;
	cin >> value;
	cout << countWaysToMakeChangeDp(coins,n,value);
}