#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcase;
	cin >> testcase;
	while(testcase--){
		int n;
		cin >> n;
		vector<int> arr(2*n,0);
		for(ll i = 0 ; i < 2*n; i++){
			cin >> arr[i] ;
		}
		set<int> check;
		for(int i = 0; i < 2*n; i++){
			check.insert(arr[i]);
		}
		if(check.size()!=n){
			cout << "NO" << endl;
			continue;
		}
		vector<int> v;
		for (int i:check)
		{
			v.push_back(i);
		}
		int flag = 1;
		int sum = 0;
		for (int i = n-1; i>=0; i--)
		{
			v[i] -= sum;
			if(v[i]>0&&(v[i]%(2*(i+1)))==0){
				v[i]/=(2*(i+1));
				sum+=2*v[i];
			}else{
				flag = 0; 
				break;
			}
		}
		if(flag){
			cout << "YES" << endl;
		}else{
			cout << "NO" <<endl;
		}
	}
}