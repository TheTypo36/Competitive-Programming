#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll binarySearch(ll* input,ll n, ll left, ll right, ll student)
{
   int ans = 0;
   while(left <= right){
   		int mid = (left + right)/2;
   		int sum = 0;
   		for (int i = 0; i < n; ++i)
   		{
   			sum+=(input[i]/mid);
   		}
   		//cout <<"mid: " << mid << endl;
   		//cout << "sum: " << sum << endl;

   		if(sum >= student){
   			ans = mid;
   			left = mid + 1;	
   		}
   		else{
   			right = mid - 1;
   		}
   }
   return ans;
}
int main()
{
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		ll n, k;
		cin >> n >> k;
		ll* input = new ll[n];
		for (ll i = 0; i < n; ++i)
		{
			cin >> input[i];
		}
		sort(input,input+n);
		
		cout << binarySearch(input,n,0,input[n-1], k) << endl;
	}
	return 0;
}