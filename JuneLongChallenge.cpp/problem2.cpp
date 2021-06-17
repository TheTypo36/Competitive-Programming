#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int testcases;
	cin >> testcases;

	while(testcases--){
		ll D, d, p, Q;
		cin >> D >> d >> p >> Q;

		
		ll totalDollars = 0;	
		ll n = D/d;
		ll N = D % d;
		ll completeGroup = ((n*( 2 * p + (n-1)* d))/2);
		ll incompleteGroup = N*(p+n*Q);
		//cout << " incompleteGroup: " << incompleteGroup << endl;
		//cout << " completeGroup: " << completeGroup << endl;
		totalDollars = completeGroup + incompleteGroup;
	cout << totalDollars << endl;
		
	}
}