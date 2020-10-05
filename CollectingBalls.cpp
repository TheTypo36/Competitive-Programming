#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll Distribution(ll n){
	ll low = 0, high = n;
	ll ans = INT_MAX;
	while(low < high){
		ll mid = high - (high - low) / 2;
		ll total = n;
		ll sharma = 0 ;
		while(total > 0){
			if(total > mid){
				sharma += mid ;
				total = total - mid;
				total =total-( total /10);
			}else{
				sharma +=total;
				total = 0;
			}
		}
		if(2*sharma >= n){
			ans = mid;
			high = mid - 1;
		}else{
			low = mid;
		}
	}
	return ans;
}
int main(){
	ll n;
	cin >> n;
	if(n == 1){
		cout << n << endl;
	}else{
	cout << Distribution(n);
	}
}