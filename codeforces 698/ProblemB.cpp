#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int q,d;
		cin >> q >> d;
		for (int i = 0; i < q; ++i)
		{
			
				ll x;
				 cin >> x;
				int flag = 0;
				if(x>=d*10){
					flag = 1;
				}
				if(flag == 0){
					while(x>=d){
						if(x%d==0){
							flag = 1;
							break;
						}	
						x=x-10;	
					}	
				}
			
				if(flag){
					cout << "YES" << endl;
				}else{
					cout <<  "NO" << endl;
				}
		}
	}
}