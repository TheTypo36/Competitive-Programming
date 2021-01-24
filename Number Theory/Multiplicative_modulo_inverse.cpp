#include <bits/stdc++.h>
using namespace std;
class Triplet{
	public:
		int x;
		int y;
		int gcd;

};
Triplet ExtendedEuclidAlgorithm(int a, int b){
	if(a<b){
		ExtendedEuclidAlgorithm(b,a);
	}
	if(b == 0){
		Triplet base_case;
		base_case.x = 1;
		base_case.y = 0;
		base_case.gcd = a;
		return base_case;
	}

	Triplet smallans = ExtendedEuclidAlgorithm(b,a%b);
	Triplet ans;
	ans.gcd = smallans.gcd;
	ans.x = smallans.y;
	ans.y = smallans.x-(a/b)*smallans.y;
	return ans;
}
int multiplicativeModuloInverse(int a, int m){
	Triplet ans = ExtendedEuclidAlgorithm(a,m);
	return ans.x;
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int a, m;
	cin >> a >> m;
	int b = multiplicativeModuloInverse(a,m);
	cout << b << endl;
} 