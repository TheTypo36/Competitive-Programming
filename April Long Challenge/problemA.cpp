#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int a , b, c;
	cin >> a >> b >> c;
	if(a==b||a==c||b==c){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}