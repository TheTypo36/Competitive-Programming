#include <bits/stdc++.h>
using namespace std;

int board[11][11];
bool isPossible(int n, int row, int col){
	for (int i = row - 1; i >=0; --i)
	{
		if(board[i][col] == 1){
			return false;
		}
	}
	int i = row-1 ,j = col-1;
	while(i>=0&&j>=0){
		if(board[i][j] == 1){
			return false;
		}
		i--;
		j--;
	}
	i = row-1, j = col+1;
	while(i>=0&&j<n){
		if(board[i][j] == 1){
			return false;
		}
		i--;
		j++;
	}
	return true;
}
void Nqueen(int n, int row){
	if(n==row){
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << board[i][j] << " ";
			}
		}
		cout << endl;
		return;
	}
	for (int j = 0; j < n; ++j)
	{
		if(isPossible(n,row,j)){
			board[row][j] = 1;
			Nqueen(n,row+1);
			board[row][j] = 0;
		}
	}
	return;
}
void placeNQueens(int n){
	memset(board,0,11*11*sizeof(int));
	Nqueen(n,0);
}
int main(){
	int n;
	cin >> n;
	placeNQueens(n);
}