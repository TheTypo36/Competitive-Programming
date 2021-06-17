#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	int sp = 0;
	for(int row = 0 ; row < n; row++){

		for(int col = 1; col <= n-row; col++){
			cout << col ;
		}
		for(int s = 0 ;  s < sp ; s++){
			cout << '*' ;
		}
		for(int col = n-row ; col>=1; col--){
			cout << col;
		}
		sp = sp + 2;
		cout << endl;
	}
}