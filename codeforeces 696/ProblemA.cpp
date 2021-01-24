#include <bits/stdc++.h>
using namespace std;

int main(){
	int testcase;
	cin >> testcase;
	while(testcase--){
		int n;
		cin >> n;
		vector<int> b(n);
		string strb;
		cin >> strb;
		for(int i = 0; i < n;i++){
			int x = strb[i]-'0';
			 b[i] = x;
		}
		std::vector<int> a(n);
		int left = -1;
		int j = 0;
		while(j<n){
			if(left==-1){
				a[j] =1;
			}
			else if(left==1){
				if(b[j]==1){
					a[j] = 1;
				}else{
					a[j] = 0;
				}
			}else if(left == 2){
				if(b[j]==1){
					a[j] = 0;
				}else{
					a[j] = 1;
				}
			}else{
				if(b[j]==1){
					a[j] = 1;
				}else{
					a[j] = 1;
				}
			}
			//cout << "left:" << left << " a[j]:" << a[j] << " b[j]:" << b[j]<< endl;
			left = a[j] + b[j];
			j++;
		}
		for(int  i = 0; i!=n;i++){
			cout << a[i] ;
		}
		cout << endl;
	}
}