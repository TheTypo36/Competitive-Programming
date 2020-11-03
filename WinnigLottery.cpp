#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin >> n;
	int d; 
	cin >> d;
	int numleft = n - 1;
	int dleft = d - 1;
	string ans;
	while(dleft--){
		if(numleft >=9){
			ans = ans + to_string(9);
			numleft = numleft - 9;
		}else if(numleft==0){
			ans = ans + to_string(0);
		}else{
			ans += to_string(numleft);
			numleft = 0;
		}
	}
	ans = ans + to_string(1);
	reverse(ans.begin(),ans.end());
	cout << ans << endl;
	cout << endl;
}