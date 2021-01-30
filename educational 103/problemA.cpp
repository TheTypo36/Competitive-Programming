#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	while(testcase--){
		int n,k;
		cin >> n>>k;
		if(n%k==0){
			cout << 1 << endl;
		}
		else if(n>k){
			cout << 2 << endl;
		}else if(n<k){
			if(k%n==0){
				cout << k/n << endl;
			}else{
			
				 cout << k/n+1 << endl;
		
		}
	}
		
	}
}
