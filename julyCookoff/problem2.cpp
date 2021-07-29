#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define F first
#define S second
typedef long long ll;

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		ll x,y;
		cin >> x >> y;
		if(x>y){
			ll temp = y;
			y = x;
			x = temp;
		}
		//cout << x << y << endl;
		if(y%x==0){
			cout << 0 << endl;
		}else if(__gcd(x,y)>1){
			cout << 0 << endl;
		}
		else if(x%2==0 && y%2==0){
			cout << 0 << endl;
		}else if((y+1)%x==0||__gcd(x,(y+1))>1){
				cout << 1 << endl;
		}else if(y%(x+1)==0||__gcd(y,(x+1))>1){
				cout << 1 << endl;

		}else if( x%2==1 && y%2==1){
				cout << 2 << endl;
		}else{
			cout << 1 << endl;
		}


		
	}
	return 0;
}