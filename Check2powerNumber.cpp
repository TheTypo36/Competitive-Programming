#include <bits/stdc++.h>
using namespace std;

void check2power(int n ){
	if((n&(n-1))==0)
	{
		cout <<n<< " is power of 2" << endl;
	}else{
		cout << n<< " is not power of 2" << endl;
	}
	return;
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		check2power(i) ;
	}
	
}