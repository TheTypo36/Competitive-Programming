#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MP make_pair
#define F first
#define S second
typedef long long ll;

ll minTime(ll totalSliceWant, ll* arr){
	if(totalSliceWant<=0){
		return 0;
	}
	if(arr[totalSliceWant]!=0){
		return arr[totalSliceWant];
	}
	ll smallPizza = 15+minTime(totalSliceWant-6,arr);
	ll mediumPizza = 20+minTime(totalSliceWant-8,arr);
	ll largePizza = 30+minTime(totalSliceWant-10,arr);

	return arr[totalSliceWant]=min(smallPizza,min(mediumPizza,largePizza));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		ll n;
		cin >> n;
		ll* arr = new ll[n](0);
		cout << minTime(n,arr) <<endl;
	}	
	return 0;
}