#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ll n, x,y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	ll group ;
	if(s[0] == '0'){
		group = 1;
	}
	else if(s[0] == '1'){
		group = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		if(i+1<n && s[i] == '1' && s[i+1] == '0'){
			group++;
		}
	}
	cout << group << endl;
	if(group == 0){
		cout << 0 << endl;
	}else{
		ll ans = (group - 1) * min(x, y) + y ;
		cout << ans << endl;
	}
}