#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);


	ll n ;
	cin >> n;
	int * arr = new int[n+1];
	for(ll i = 0; i < n; i++){
		cin >> arr[i];
	}
	unordered_map<ll,ll> freq;
	for(ll i = 0; i < n; i++){
		freq[arr[i]]++;
	}

	// for(ll i = 0; i < n; i++){
	// 	cout <<"element: " <<arr[i] <<" their frq: "<< freq[arr[i]] << endl;;
	// }
	ll m = n -1;
	ll pair= 0;
	for(ll i=0; i <= m; i++){

		if(freq[arr[i]]<2){
			pair += (m-i);
		//	cout << arr[i] << freq[arr[i]] << pair << endl;
		}else{

			pair += ((m-i)-(freq[arr[i]]-1));
			freq[arr[i]]--;
			//cout << arr[i] << freq[arr[i]] << pair << endl;

		}
	}
	cout << pair << endl;
}