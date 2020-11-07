#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(vector<int>  &arr, int n){
	int ans = 0;
	int left = arr[0];
	for(int i = 1; i < n; i++){
		 int curr_min = min(left, arr[i]);
		 left  -= curr_min;
		 arr[i]  -= curr_min;
		 ans += curr_min;
		 left = max(arr[i], left);
	}
	return ans;
}
int main()
{
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		int n;
		cin >> n;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; ++i)
		{

				cin >> arr[i];
		}
		sort(arr.begin(), arr.end(), greater<int>());
		if(n == 1){
			cout << arr[0];
			return 0;
		}
		cout << solve(arr, n) << endl;
	}
	return 0;
}