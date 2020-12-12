#include <bits/stdc++.h>
using namespace std;

vector<int> getPathDFS(int** egdes, int n, int sv, int ev, bool* visited){
	if(sv == ev){
		vector<int> base_case;
		base_case.push_back(sv);
		return base_case;

	}
	visited[sv] = true;
	for (int i = 0; i < n; ++i)
	{
		if(sv == i){
			continue;
		}
		if(egdes[sv][i] == 1 && !visited[i]){
			std::vector<int> recurans = getPathDFS(egdes,n,i,ev,visited);
			if(recurans.size()!=0){
				recurans.push_back(sv);
				return recurans;
			}
		}
	}
	std::vector<int> v;
	return v;
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
		for (int j = 0; j < v; ++j)
		{
			egdes[i][j] = 0;
		}
	}
	while(e--){
		int f, s;
		cin >> f >> s;
		egdes[f][s] = 1;
		egdes[s][f] = 1;
	}
	int v1,v2;
	cin >> v1 >> v2;
	bool * visited = new bool[v];
	for (int i = 0; i < v; ++i)
	{
		visited[i] = false;
	}
	std::vector<int> ans = getPathDFS(egdes,v,v1,v2,visited);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	for (int i = 0; i < v; ++i)
	{
		delete [] egdes[i];
	}
	delete [] visited;
}