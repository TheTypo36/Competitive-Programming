#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	while(testcase--){
		
		int n;
		int k;
		cin >> n >> k;
		vector<int> v(n,0);
		int correct = 0;
		int tooSlow = 0;
		int bot = 0;
		for(int i = 0 ; i < n; i++){
			cin >> v[i];
			if(v[i]!=-1){
				correct++;
			}
			if(v[i]>k){
				tooSlow = 1;
			}
			if(v[i] <= 1&&v[i]!=-1){
				bot++;
			}
		}

		if(correct<((n+1)/2)){
			cout << "Rejected" << endl;
			continue;
		}
		if(tooSlow ==1){
			cout << "Too Slow" << endl;
			continue;
		}
		if(bot == n){
			cout << "Bot" <<endl;
			continue;
		}
		cout << "Accepted" << endl;

	}
}