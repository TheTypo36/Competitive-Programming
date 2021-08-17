#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define F first
#define S second
typedef long long ll;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcases;
	cin >> testcases;
	int n = 1e5;
	int arr[n+1];
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	for(int i = 3; i <= 1e5; i++){
		arr[i] = arr[i-1]+ i-1;
	}
	while(testcases--)
	{
		ll n;
		cin >> n;
		cout << arr[n] << endl;
		
	}
	return 0;
}