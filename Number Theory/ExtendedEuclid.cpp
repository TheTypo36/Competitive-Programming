#include <bits/stdc++.h>
using namespace std;

class Triplet{
	public:
		int x;
		int y;
		int gcd;
};
Triplet extendEuclidAlgo(int a, int b){
	//base case
	if(b == 0){
		Triplet base_case;
		base_case.gcd = a;
		base_case.x = 1;
		base_case.y = 0;
		return base_case;
	}

	//recursive call
	Triplet smallans = extendEuclidAlgo(b,a%b);
	Triplet ans ;
	ans.gcd = smallans.gcd;
	ans.x = smallans.y;
	ans.y =smallans.x - (a/b)*smallans.y;
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	Triplet ans = extendEuclidAlgo(a,b);
	cout << ans.gcd << endl;
	cout << ans.x << endl;
	cout << ans.y << endl;
}