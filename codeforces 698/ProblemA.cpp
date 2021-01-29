#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int  testcase;
	cin >> testcase;
	while(testcase--){
		int n;
		cin >> n;
		vector<int> arr(n,0);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		unordered_map<int,int> freq;
		for (int i = 0; i < n; ++i)
		{
			freq[arr[i]]++;
		}
		int max = 0;
		for (int i = 0; i < n; ++i)
		{
			if(max<freq[arr[i]]){
				max=freq[arr[i]];
			}
		}
		cout << max << endl;
	}
}