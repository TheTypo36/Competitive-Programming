#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcases;
	cin >> testcases;
	while(testcases--){
		int d , x, y , z;
		cin >> d >> x >> y >> z;


		int s1 = x*7;
		int s2 = d*y + ((7-d)*z);

		cout << max(s1,s2) << endl;
	}
}