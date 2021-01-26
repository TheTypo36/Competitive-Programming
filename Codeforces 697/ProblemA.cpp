#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll n){
		ll ans  = 2;
		for(int i = 1; i <=60 ; i++){
			if(pow(ans,i)==n){
				cout  << "NO" << endl;
				return;
			}
		}
		cout << "YES" << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcases;
	cin >> testcases;
	while(testcases--){
		ll n;
		cin >> n;
		solve(n);
	}
}
