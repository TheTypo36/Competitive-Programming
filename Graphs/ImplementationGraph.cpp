#include <bits/stdc++.h>
using namespace std;
void bfs(int** egdes, int n, int sv,bool*visited){
	
	queue<int> left;
	left.push(sv);
	visited[sv] = true;

	while(!left.empty()){
		int front = left.front();
		left.pop();
		cout << front << " ";
		
		for(int i = 0; i < n; i++){
	
			if(egdes[front][i] == 1 && !visited[i]){
				left.push(i);
				visited[i] = true;
			}
		}


	}
}
void printdfs(int** egdes, int n, int sv, bool* visited){
	cout << sv << endl;
	visited[sv] = true;
	for (int i = 0; i < n; ++i)
	{	
		if(i == sv){
			continue;
		}
		if(egdes[sv][i] == 1 && !visited[i]){
			printdfs(egdes, n, i, visited);
		}
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	int egde;
	cin >> n >> egde;
	int** egdes = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		egdes[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			egdes[i][j] = 0;
		}
	}

	for (int i = 0; i < egde; ++i)
	{
		int f, s;
		cin >> f >> s; 
		egdes[f][s] = 1;
		egdes[s][f] = 1;
	}

	bool* visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
	//printdfs(egdes,n,0,visited);
	for (int i = 0; i < n; ++i)
	{
		if(!visited[i]){

	 		bfs(egdes,n,0,visited);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		delete egdes[i];
	}
	delete []egdes;

	delete []visited;


}