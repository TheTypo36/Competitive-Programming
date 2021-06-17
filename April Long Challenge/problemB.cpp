#include <bits/stdc++.h>
using namespace std;
double round(double result){
	return floor((result*100)+0.5)/100;
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
		int testcase;
		cin >> testcase;
		while(testcase--){
			double k1, k2 , k3, v;
			cin >> k1 >> k2 >> k3 >> v;
			double result = 100/(k1*k2*k3*v);
			result = round(result);
			//cout << result << endl;
			if(result<9.58){
				cout << "YES" << endl;
			}else{
				cout << "NO" << endl;
			}
		}
}