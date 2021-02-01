#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	while(testcase--){
		vector<int> v(3);
		for(int i = 0 ; i < 3; i++){
			cin >> v[i];
		}
		sort(v.begin(),v.end());
		if(v[2]==(v[0]+v[1])){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}	
}