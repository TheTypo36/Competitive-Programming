#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		int n, k;
		cin >> n >> k;
		int* input = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> input[i];
		}
		sort(input,input+n,greater<int>());
		
		cout << input[k-1] << endl;
	}
	return 0;
}