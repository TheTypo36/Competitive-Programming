#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	while(testcase--){
		int l , r;
		cin >> l >> r;
		int ans = ((r+r) - (l+l))+1;
		cout << ans << endl;
	}
}