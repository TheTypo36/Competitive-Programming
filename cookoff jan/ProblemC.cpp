#include <bits/stdc++.h>
using namespace std;

unordered_map<int,bool> prime;
std::vector<int> v;
int mod = 1000000;
int sieve[1000000];
int ans[1000000]{};
void sieveEratos(){
	for (int i = 0; i <= mod; ++i)
	{
		sieve[i] = true;
	}
	sieve[0] = false;
	sieve[1] = false;
	 for (int i = 2; i*i <= mod; ++i)
	 {
	 	if(sieve[i] == true){
	 		int j = i*i;
	 		while(j<=mod){
	 			sieve[j] = false;
	 			j+=i;
	 		}
	 	}
	 }

	
	for (int i = 2; i <=mod ; ++i)
	{
		if(sieve[i] == true){
			prime.insert(pair<int,bool>(i,true));
			v.push_back(i);
		}
	}
	int count = 0;
	for(int i = 5; i <= mod; i++){
		if(sieve[i] && sieve[i-2]){
			count++;
		}
		ans[i] = count;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	sieveEratos();
	while(testcase--){
		int n;
		cin >> n;
		if(n < 4){
			cout << 0 << endl;
		}else{
			cout << ans[n] << endl;
		}
	}
}