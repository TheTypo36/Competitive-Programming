#include <bits/stdc++.h>
using namespace std;

void print(int** egdes, int n, int sv, bool* visited){
	cout << sv << endl;
	visited[sv] = true;
	for (int i = 0; i < n; ++i)
	{	
		if(i == sv){
			continue;
		}
		if(egdes[sv][i] == 1 && !visited[i]){
			print(egdes, n, i, visited);
		}
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	int edge;
	cin >> n >> edge;
	int** edges = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			edges[i][j] = 0;
		}
	}

	for (int i = 0; i < edge; ++i)
	{
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	print(edges,n,0,visited);
	delete []visited;
	for (int i = 0; i < n; ++i)
	{
		delete edges[i];
	}
	delete []edges;



}