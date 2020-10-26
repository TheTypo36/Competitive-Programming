#include <bits/stdc++.h>
using namespace std;

int total_min_fare(int** strg,int row, int col, int n, int m)
{
	if(row >= n || col >= m){
		return INT_MAX;
	}
	int option1 = total_min_fare(strg,row,col+1,n,m);
	int Curr_fare = strg[row][col];
	int option2 = INT_MAX;
	for (int i = col; i < m; ++i)
	{
		if(Curr_fare == strg[row+1][i] || Curr_fare - 1 == strg[row+1][i] || Curr_fare + 1 == strg[row+1][i]){
			 option2 = min(option2,total_min_fare(strg,row+1,i,n,m));
		}
	}
	return min(option1,Curr_fare+option2);
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	int m; 
	cin >> m;
	int** strg = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		strg[i] = new int[m];
		for (int j = 0; j < m; ++j)
		{
			cin >> strg[i][j];
		}
	}
	cout << total_min_fare(strg,0,0,n,m) << endl;
}