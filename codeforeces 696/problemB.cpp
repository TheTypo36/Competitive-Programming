#include <bits/stdc++.h>
using namespace std;

int sieve[100002];
int mod = 100002;
void SieveEratosthenes(int n){
	for(int i = 0; i <=n;i++){
		sieve[i]=true;
	}
	sieve[0] = false;
	sieve[1] = false;
	 for (int i = 2; i*i <= n; ++i)
	 {
	 	if(sieve[i] == true){
	 		int j = i*i;
	 		while(j<=n){
	 			sieve[j] = false;
	 			j+=i;
	 		}
	 	}
	 }

}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcase;
	cin >> testcase;
	while(testcase--){
		int d;
		cin >> d;
		SieveEratosthenes(mod);
		int p=1;
		while(p<=100000){
			if(sieve[p]==true&&(p-1)>=d){
				break;
			}
            p++;
		}
		int q = p;
		while(q<=100000){
			if(sieve[q]==true&&(q-p)>=d){
				break;
			}
            q++;
		}
		int ans = q*p;
		cout << ans << endl;
	}

}