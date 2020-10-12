#include <bits/stdc++.h>
using namespace std;
int minCostDp(int** grid, int row, int col, int n){
	vector<vector<int>> strg(n+1, vector<int>(n+1, 0));
		int sum = 0;
		//cout << n << endl;
	for (int i = n; i >=0; i--)
	{
		sum+= grid[i][n];
		//cout << sum <<endl;
		strg[i][n] = sum;
	}
	sum = 0;
	for (int i = n; i >=0; i--)
	{
		sum+= grid[n][i];
		//cout << sum << endl;
		strg[n][i] = sum;	
	}
	for (int i = n-1; i >=0 ; --i)
	{
		for (int j = n-1; j >= 0; --j)
		{
			strg[i][j] = grid[i][j]+min(strg[i][j+1],min(strg[i+1][j],strg[i+1][j+1]));
		}
	}
	return strg[0][0];
}
int minCost(int** grid,int row, int col,int n,vector<vector<int>> strg){
	if(row == n && col == n){
		return grid[row][col] ;
	}
	if(row > n || col > n){
		return INT_MAX;
	}
	if(strg[row][col]!=-1){
		return strg[row][col];
	}

	int ans = grid[row][col]+min(minCost(grid,row+1,col,n,strg),min(minCost(grid,row+1,col+1,n,strg),minCost(grid,row,col+1,n,strg)));
	return strg[row][col]=ans;

}
int main(){
	int n;
	cin >> n;
	int** grid = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		grid[i] = new int[n];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{

			cin >> grid[i][j] ;

		}
	}
	vector<vector<int>> v(n+1, vector<int>(n+1, -1));
	 cout << minCostDp(grid,0,0,n-1);
}