#include <bits/stdc++.h>
using namespace std;
int staircase(int n,int * strg){
		if(n < 0)
	{
		return 0; 
	}
	if( n == 0)
	{
		return 1;
	}

	if(strg[n]!=-1){
		return strg[n];
	}

	int f1 = staircase(n - 1,strg);
	f1+= staircase(n-2,strg);
	f1+=staircase(n-3,strg);

	return strg[n]=f1; 
}
int staircase_recur(int n)
{
	if(n < 0)
	{
		return 0; 
	}
	if( n == 0)
	{
		return 1;
	}


	int f1 = staircase_recur(n - 1);
	f1+= staircase_recur(n-2);
	f1+=staircase_recur(n-3);

	return f1; 
}
int main(){
	int n;
	cin >> n;
	int strg[n+1];
	for (int i = 0; i <= n; ++i)
	{
		strg[i] = -1;
	}
	cout << staircase(n,strg);
}