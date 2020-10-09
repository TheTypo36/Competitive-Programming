#include <bits/stdc++.h>
using namespace std;

void swap(int* input, int p1,int p2){
	int swap = input[p1];
	input[p1] = input[p1+p2];
	input[p1+p2] = swap;
}
int main(){
	int n;
	cin >> n;
	int *pos = new int[n];
	for(int i = 0 ; i < n ; i++){
		cin >> pos[i] ;
	}
	int *players = new int[n];
	for (int i = 0; i < n; ++i)
	{
		players[i] = i + 1;
	}
	int ans = 0;
	//1 2 3 4 5
	for(int i = 0 ; i < n; i++){
		if(players[i] == pos[i]){
			continue;
		}
		else{
			
				int swap = pos[i+1];
				pos[i+1] = pos[i];
				pos[i] = swap;
				ans++;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if(pos[i]!=players[i]){
			cout << "NO" << endl;
		return 0;
		}
	}
	cout << "YES" << endl;
	cout << ans << endl;

}