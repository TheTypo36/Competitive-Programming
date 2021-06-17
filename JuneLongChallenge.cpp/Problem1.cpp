#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int  testcases;
	cin >> testcases;
	while(testcases--){
		int xa, xb, Xa, Xb;
		cin >> xa >> xb >> Xa >> Xb;
		int ans = (Xa/xa) + (Xb/xb);
		cout << ans << endl;
	}
}