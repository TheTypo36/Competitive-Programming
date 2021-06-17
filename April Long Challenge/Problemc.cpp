	#include <bits/stdc++.h>
	using namespace std;

	int main(){

		ios_base::sync_with_stdio(false);
		cout.tie(NULL);

		int testcases;
		cin >> testcases;
		while(testcases--){
			int n , k;
			cin >> n >> k;
			if(k>n){
				cout << "NO" << endl; 
				continue;
			}
			string str;
			cin >> str;
			int finalCount = 0;
			int flag = 0;
			for(int i = 0 ; i < n; i++){
				if(str[i]=='*'){
					int count = 0;
					////cout << i<< " pos" << endl;
					while(str[i]=='*'&& i<n){
						i++;
						count++;
					}
					//cout << count <<" cout "<< endl;
				
					finalCount=max(finalCount,count);
				}
			}
			if(finalCount>=k){
				cout << "YES" << endl;
			}else{
				cout << "NO" << endl;
			}
		}
	}