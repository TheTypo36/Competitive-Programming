#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	
		int n;
		cin >> n;
	
		int m;
		cin >> m;
		int size = 1000001;
		vector<int> starting(size, 0);
		vector<int> ending(size, 0);
		vector<int> dpCoins(size, 0);
		for (int i = 0; i < m; ++i)
		{
			int l, r;
			cin >> l>> r;
			starting[l]++;
			ending[r]++;
		}
		dpCoins[0] = 0;
		dpCoins[1] = starting[1];
		for (int i = 2; i < size; ++i)
		{
			dpCoins[i] = starting[i] + dpCoins[i-1]  - ending[i-1];
		}
		vector<int> dpBox(size, 0);
		for (int i = 0; i < size; ++i)
		{
			dpBox[dpCoins[i]]++;
		}
		vector<int> ans(n+1,0);
		ans[n] = dpBox[n];
			ans[0] = n;
		for (int i = n-1; i >= 0; i--)
		{
		
			ans[i] = ans[i+1] + dpBox[i];
		}
		int q;
		cin >> q;
		while(q--)
		{
			int qi;
			cin >> qi;
			cout << ans[qi] << "\n";
		}

	return 0;
}