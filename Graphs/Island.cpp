#include <bits/stdc++.h>
using namespace std;

void dfs(int** egdes,int n, int sv, bool * visited){
	visited[sv] = true;
	for (int i = 0; i < n; ++i)
	{
		if(sv==i){
			continue;
		}
		if(egdes[sv][i] == 1 && !visited[i]){
			dfs(egdes,n,i,visited);
		}
	}
}
int main(){

	ios_base:: sync_with_stdio(false);
	cout.tie(NULL);

	int n,e;
	cin >> n >> e;
	int** egdes = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		egdes[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			egdes[i][j] = 0;
		}
	}
	while(e--){
		int s, f;
        cin >> s >> f;
		egdes[s][f] = 1;
		egdes[f][s] = 1;
	}
	bool* visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}
    int ans = 0;
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			
			dfs(egdes,n,i,visited);
            ans++;
		}
	}
    cout << ans << endl;
	

}