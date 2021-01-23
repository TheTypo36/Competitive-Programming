#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n){
	int count = 0;
	for(int  j = 1; j*j<=n; j++){
		if(n%j==0){
			if(j*j==n){
  				count++;
			}else{
				count+=2;
			}

		}
	}
	if(count==2){
		return true;
	}else{
		return false;
	}
}
void dummySieveOfEratosthenes(int n){
	vector<bool> sieve(n+1,true);
	sieve[0] = false;
	sieve[1] = false;
	int count = 0;
	for(int i = 2; i*i <= n; i++){
		if(sieve[i]==false){
			continue;
		}
			int j = i;
			while(j*i<=n){
				sieve[i*j]=false;
				j++;
		}
	}
	for (int i = 0; i <= n; ++i)
	{
		/* code */
		if(sieve[i])
			count++;
	}
	cout << count << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	// int count = 0;
	// for(int i = 1; i <= n; i++){
	// 	if(checkPrime(i)){
	// 		count++;
	// 	}
	// }
	// cout << count << endl;
	dummySieveOfEratosthenes(n);
}