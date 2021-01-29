#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Triplet{
public:
	ll x;
	ll y;
	ll gcd;
};
Triplet extendedEuclidAlgorithm(ll a, ll b){
	if(b == 0){
		Triplet base_case;
		base_case.x=1;
		base_case.y=0;
		base_case.gcd = a;
		return base_case; 
	}
	Triplet smallans = extendedEuclidAlgorithm(a,b);
	Triplet ans ;
	ans.gcd = smallans.gcd;
	ans.x = smallans.y;
	ans.y = smallans.x - (a/b)*smallans.y;
	return ans;

}
int mmInverse(int a, int m){
	Triplet ans = extendedEuclidAlgorithm(a,m);
	ans.x;
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	while(testcase--){
		ll a ,b , d;
		cin >> a >> b >> d;
		int y1 = (d/b)%a;
		int n = ((d/b)-y1)/a;
		cout << n << endl;
	}
}