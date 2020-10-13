#include <bits/stdc++.h>
using namespace std;

int maxMoneyLooted(int * house, int n)
{
	if( n == 0)
	{
		return 0;
	}
	int strg[n];
	strg[0] = house[0];
	if(n > 1){
		strg[1] = max(house[0], house[1]);
	}
	for (int i = 2; i < n; ++i)
	{
		strg[i] = max(strg[i-1], strg[i-2]+house[i]);
	}
	return strg[n-1];
}
int main(){
	int n;
	cin >> n;
	int* house = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> house[i] ;
	}
	cout << maxMoneyLooted(house,n) << endl;
}