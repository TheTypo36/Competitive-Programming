#include <bits/stdc++.h>
using namespace std;

void dfs(int** egdes, int n, int sv, bool* visited){
	visited[sv] = true;
	for(int i = 0; i < n; i++){
		if(i==sv){
			continue;
		}
		if(egdes[sv][i] == 1 && !visited[i]){
			dfs(egdes,n,i,visited);
		}
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n, e;
	cin >> n >> e;
	int** egdes = new int*[n];
	for(int i = 0 ; i < n; i++){
		egdes[i] = new int[n];
		for(int j = 0; j < n; j++){
			egdes[i][j] = 0;
		}
	}
	while(e--){
		int s, f;
		cin >> s >> f;
		egdes[f][s] = 1;
		egdes[s][f] = 1;

	}

	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}

	dfs(egdes,n,0,visited);
	for(int i = 0; i < n; i++){
		if(visited[i]==false){
			cout << "false" << endl;
			return 0;
		}
	}
	cout << "true" << endl;
}