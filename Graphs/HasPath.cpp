#include <bits/stdc++.h>
using namespace std;
bool hasPath(int** egdes, int n, int sv, int ev, bool* visited){
	if(egdes[sv][ev]==1){
		return true;
	}
	visited[sv] = true;
	for (int i = 0; i < n; ++i)
	{
		if(i==sv){
			continue;
		}
		if(egdes[sv][i] == 1&&!visited[i]){
			bool ans = hasPath(egdes,n,i,ev,visited);
			if(ans){
				return true;
			}
		}
	}
	return false;
}
int main(){
	ios_base:: sync_with_stdio(false);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;
	int** egdes = new int*[v];
	for (int i = 0; i < v; ++i)
	{
		egdes[i] = new int[v];
		for(int j = 0 ;j < v ; j++){
			egdes[i][j] = 0;
		}
	}
	while(e--){
		int f, s;
		cin >> f >> s;
		egdes[s][f] = 1;
		egdes[f][s] = 1;
	}
	int v1 , v2;
	cin >> v1 >> v2;
	bool* visited = new bool[v];
	if(hasPath(egdes,v,v1,v2,visited)){
		cout << "true" << endl;
	}else{
		cout << "false" << endl;
	}
	for (int i = 0; i < v; ++i)
	{
		delete [] egdes[i];
	}
	delete [] egdes;
}