#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MP make_pair
#define F first
#define S second
typedef long long ll;

int CountBit(int n){
	int count = 0;
	while(n>0){
		
		count +=(n&1);

		n>>=1;
	}
	return count;
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << CountBit(n) << endl;
}