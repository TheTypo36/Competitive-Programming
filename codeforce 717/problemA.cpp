#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcase;
	cin >> testcase;
	while(testcase--){
		int n,k;
		cin >> n >> k;
		int* arr = new int[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		while(k--){
			if(arr[i]==0){
				break;
			}
			arr[0]--;
			arr[n-1]++;
		}
		for(int i = 0; i < n; i++){
			cout << arr[i] << " ";
		}
	}

}