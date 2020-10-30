#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin >> n;
	int* cakes = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> cakes[i];
	}
	sort(cakes,cakes+n, greater<int>());
	ll sum = 0;
	for (int i = 0; i < n; ++i)
	{
		ll calc = cakes[i] * pow(2,i);
		sum += calc ;
	}
	cout << sum << endl;
}