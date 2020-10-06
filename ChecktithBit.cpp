#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int i ;
	cin >> i;
	int z = n&(1<<i);
	if(z==0){
		cout << i << "t
		h bit was not set" << endl;
	}else{
		cout << i <<"th bit was set" << endl;
	}
}