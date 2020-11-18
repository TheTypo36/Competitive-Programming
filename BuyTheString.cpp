#include <bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int testcases;
	cin >> testcases;
	while(testcases--){
		int n, c0, c1, h;
		cin >> n >> c0 >> c1 >> h;
		string s;
		cin >> s;
		int costOfAllZeros = 0;
		int costOfAllone = 0;
		for(int i = 0 ; i < n; i++){
			if(s[i] == '1'){
				costOfAllZeros += h;
			}else{
				costOfAllone += h;
			}

		}
		costOfAllZeros += (c0 * n);
		costOfAllone += (c1 * n);
		int toogleCost = 0;
		for(int i = 0 ; i < n; i++){
			if(s[i] == '1'){
				toogleCost += c1;
			}else{
				toogleCost +=c0;
			}
		}
		cout << min(toogleCost,min(costOfAllZeros,costOfAllone)) << endl;
	}
}