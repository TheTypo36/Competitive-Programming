#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	while(testcase--){
		int n;
		cin >> n;
		vector<int> v(n,0);
		for(int i = 0 ; i < n; i++){
			cin >> v[i];
		}
		int ecount = 0, ocount=0;
		for(int i = 0; i < n ; i++){
				if(v[i]%2==0){
					ecount++;
				}else{
					ocount++;
				}
		}
		cout << min(ecount,ocount) << endl;
	}
}