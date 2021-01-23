#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int** edges = new int[n];
	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
				edges[i][j] = 0;
		}
	}
	cin >> v;
	while(v--){
		int s, f;
		edges[s][f]=1; 
		edges[f][s]=1; 
	}
	bool* visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < n; ++i)
	{
		
	}
}