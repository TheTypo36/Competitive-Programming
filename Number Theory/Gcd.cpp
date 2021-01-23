#include <bits/stdc++.h>
using namespace std;

int EuclidAlgorithm(int a, int b){
	if(a==0){
		return b;
	}
	if(b==0){
		return a;
	}
	return EuclidAlgorithm(b,a%b);
}
void NaiveApproach(int a, int b){
	int gcd = 0;
	for(int  i = 1; i < min(a,b); i++){
		if(a%i==0&&b%i==0){
			gcd = i;
		}
	}
	cout << gcd << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	NaiveApproach(a,b);
	cout << EuclidAlgorithm(a,b) << endl;
}