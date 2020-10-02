#include <bits/stdc++.h>
using namespace std;

int output[11][11];
void helper(int maze[][20] ,int row, int col , int n){
	if(row < 0|| col < 0){
		return;
	}
	if(col>=n||row>=n){
		return;
	}
	if(maze[row][col] == 0 || output[row][col] == 1){
		return;
	}
	if(row == n-1 && col == n-1){
				output[row][col] = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << output[i][j] << " ";
			}
		}
		cout << endl;
		output[row][col] = 0;
		return;
	}
	
		output[row][col] = 1;
		helper(maze,row,col+1,n);
		helper(maze,row,col-1,n);
		helper(maze,row+1,col,n);
		helper(maze,row-1,col,n);
		output[row][col] = 0;
	return;
}
void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
	memset(output,0,sizeof(output));
	helper(maze, 0, 0 , n);

}

int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}


