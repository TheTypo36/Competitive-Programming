#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcase;
	cin >> testcase;
	while(testcase--){
		int n;
		cin >> n;
		map<long long,long long> m1;
		 vector<long long>arr(2*n);
		for (int i = 0; i < 2*n; i++)
		{
			cin >> arr[i];
			m1[arr[i]]++;
		}
		vector<long long> arr2(n);
		int  i = 0;		
		int found = 1;
		for(auto it:m1){
			if(it.second<2){
				found = 0;
				break;
			}
				arr2[i] = it.first;
				i++;
	
		}
		if(found==0){
			cout << "NO" <<endl;
			continue;
		}

		long long presum = 0;
		for(int i =arr2.size()-1 ;  i >=0 ; i--){
			arr2[i] = (arr2[i] - presum);
			if(arr2[i]>0 && arr2[i]%(2*(i+1))==0){
				arr2[i]=(arr2[i]/(2*(i+1)));
				presum=(presum+(2*arr2[i]));
			}else{
				found = 0;
				break;
			}
		}
		if(found==0){
			cout << "NO" << endl;
		}else{
			cout << "YES" <<endl;
		}
	}
}