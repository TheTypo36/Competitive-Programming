#include <bits/stdc++.h>
using namespace std;
int minStrength(int** grid, int row, int col, int n,int m)
{
	std::vector<vector<int>> strg(n+1, vector<int>(m+1,0));
	strg[n][m] = 1;
	strg[n-1][m] = 1;
	strg[n][m-1] = 1;
	for (int i = n-2; i >=0; i--)
	{
		strg[i][m] = strg[i+1][m] - grid[i+1][m];
		if(strg[i][m] < 1){
			strg[i][m] = 1;
		}

	}
	for (int i = m-2; i >=0; i--)
	{
		strg[n][i] = strg[n][i+1]-grid[n][i+1];
		if(strg[n][i] < 1){
			strg[n][i] = 1;
		}
	}
	for (int i = n-1 ; i >=0; i--)
	{
		for (int j = m-1; j >=0; j--)
		{
			int option1 = strg[i+1][j] - grid[i+1][j];
			int option2 = strg[i][j+1] - grid[i][j+1];
			strg[i][j] = min(option2,option1);
			if(strg[i][j] < 1){
				strg[i][j] = 1;
			}
		}
	}
	
	return strg[0][0];
}
int main(){
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		int n,m;
		cin >> n >> m;
		int **grid = new int*[n];
		for (int i = 0; i < n; ++i)
		{
			grid[i] = new int[m];	
			for (int j = 0; j < m; ++j)
			{
				cin >> grid[i][j];
			}
		}
		cout << minStrength(grid,0,0, n-1 , m-1) << endl;
	}
}