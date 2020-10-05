#include <bits/stdc++.h>
using namespace std;
bool checkRow(int board[9][9], int row, int num){
  for (int i = 0; i < 9; ++i)
  {
    if(board[row][i] == num){
      return false;
    }
  }
  return true;
}
bool checkCol(int board[9][9], int col, int num){
  for (int i = 0; i < 9; ++i)
  {
    if(board[i][col]==num){
      return false;
    }
  }
  return true;
}
bool smallMatrixCheck(int board[9][9], int row, int col , int num){
  int rowfactor = row -(row%3);
  int colfactor = col - (col % 3);
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      if(board[rowfactor + i][colfactor + j] == num){
        return false;
      }
    }
  }
  return true;
}
bool isSafe(int board[9][9] , int row, int col , int num){
  if(checkRow(board,row,num)&&checkCol(board,col,num)&&smallMatrixCheck(board,row,col,num)){
    return true;
  }else{
    return false;
  }
}
bool empty(int board[9][9], int &row, int &col){
  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      if(board[i][j] == 0 ){
        row = i ;
        col = j;
        return true;
      }
    }
  }
  return false;
}
bool sudokuSolver(int board[][9]){

  int row , col;
  if(!empty(board,row,col)){
    return true;
  }
  for (int i = 1; i <=9; ++i)
  {
      if(isSafe(board,row,col,i)){
        board[row][col] = i;
        bool ans = sudokuSolver(board);
        if(ans){
          return true;
        }
        board[row][col] = 0;
      }
  }
  return false;
}

int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}


