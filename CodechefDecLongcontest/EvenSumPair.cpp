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
		int aeven = 0 , aodd = 0;
		for(int i = 1; i <= a; i++){
			if(i%2==0){
				aeven++;
			}else{
				aodd++;
			}
		}
		int beven = 0 , bodd = 0;
		for (int i = 1; i <=b; ++i)
		{
			if(i%2==0){
				beven++;
			}else{
				bodd++;
			}
		}
		int ans = min(beven,aeven)*min(aodd,bodd);
		cout << ans << endl;
	}
}