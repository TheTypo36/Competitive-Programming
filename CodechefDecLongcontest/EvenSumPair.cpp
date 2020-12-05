#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcases;
	cin >> testcases;
	while(testcases--){
		int a,b;
		cin >> a >> b;
		int x = 1; 
		int ans = 0;
		while(x<=a)
		{
			int y = 1;
			while(y<=b){
				int sum = x + y;
				if(sum%2==0){
					ans++;
				}
				y++;
			}
			x++;
		}
		cout << ans << endl;
	}
}