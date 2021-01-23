#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n){
	int count = 0;
	for(int  j = 1; j*j<n; j++){
		if(n%j==0){
			count++;
		}
	}
	if(count==2){
		return true;
	}else{
		return false;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	int count = 0;
	for(int i = 1; i < n; i++){
		if(checkPrime(i)){
			count++;
		}
	}
	cout << count << endl;
}