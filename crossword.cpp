#include <bits/stdc++.h>
using namespace std;
#define n 10

bool checkRow(char grid[n][n], int row, int col, string word)
{
	int j = row;
	for (int i = 0;i < word.length();i++) 
	{
		if (j > 9)
			return false;
		if (grid[j][col] == '+' || (grid[j][col] != '-' && grid[j][col] != word[i]))
			return false;
		if (grid[j][col] == '-' || grid[j][col] == word[i])
			j++;
	}
	return true;
}
bool checkCol(char cross[n][n], int r, int c, string word)
{
	int j = c;
	for (int i = 0;i < word.length();i++) {
		if (j > 9)
			return false;
		if (cross[r][j] == '+' || (cross[r][j] != '-' && cross[r][j] != word[i]))
			return false;
		if (cross[r][j] == '-' || cross[r][j] == word[i])
			j++;
	}
	return true;
}
void setRow(char grid[n][n], int row, int col, string word, bool helperArr[])
{
	for (int i = 0; i < word.length(); ++i)
	{
		if (grid[row + i][col] == '-')
		{
			grid[row + i][col] = word[i];
			//cout << grid[col+i][row] << endl;
			helperArr[i] = true;
		}else{
			helperArr[i] = false;
		}
	}
}
void setCol(char grid[n][n], int row, int col, string word, bool helperArr[])
{
	for (int i = 0; i < word.length(); ++i)
	{
		if (grid[row][col + i] == '-')
		{
			grid[row][col + i] = word[i];
			//cout << grid[col+i][row] << endl;
			helperArr[i] = true;
		}else{
			helperArr[i] = false;

		}
	}
}
void resetRow(char grid[n][n], int row, int col, string word, bool helperArr[])
{
	for (int i = 0; i < word.length(); ++i)
	{
		if (helperArr[i] == true)
		{
			grid[i + row][col] = '-';
		}
	}
}
void resetCol(char grid[n][n], int row, int col, string word, bool helperArr[])
{
	for (int i = 0; i < word.length(); ++i)
	{
		if (helperArr[i] == true)
		{
			grid[row][col + i] = '-';
		}
	}
}
void printAns(char grid[n][n]){

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << grid[i][j] ;
		}
		cout << endl;
	}
    cout << endl;
}
bool crossword(char grid[n][n], vector<string> list, int index)
{

	if (index >= list.size())
	{
    	printAns(grid);
		return true;
	}
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == '-' || grid[i][j] == list[index][0])
			{
				
				if (checkRow(grid, i, j, list[index]) == true)
				{
					bool helperArr[list[index].length()];
					setRow(grid, i, j, list[index], helperArr);
					if (crossword(grid, list, index + 1))
					{
						return true;
					}
					resetRow(grid, i, j, list[index], helperArr);
				}
				if (checkCol(grid, i, j, list[index]))
				{
					bool helperArr[list[index].length()];
					setCol(grid, i, j, list[index], helperArr);
					if (crossword(grid, list, index + 1))
					{
						return true;
					}
					resetCol(grid, i, j, list[index], helperArr);
				}
			}
		}
	}
	return false;
}
int main()
{
	char grid[n][n];
	for (int i = 0; i < n; ++i)
	{
		char input[n];
		cin >> input;
		for (int j = 0; j < n; ++j)
		{
			grid[i][j] = input[j];
		}
	}
	string s;
	cin >> s;
	std::vector<string> v(s.length());
	string str;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ';')
		{
			v.push_back(str);
			str = "\0";
			continue;
		}
		str = str + s[i];
	}
	v.push_back(str);

	crossword(grid, v, 0);

	return 0;
}