#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	while(testcase--){
		ll a ,b , d;
		cin >> a >> b >> d;
		int y1 = (d/b)%a;
		int n = ((d/b)-y1)/a;
		cout << n << endl;
	}
}