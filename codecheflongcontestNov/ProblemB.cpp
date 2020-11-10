#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		int n;
		cin >> n;
		int* input = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> input[i];
		}
		for (int i = 0; i <n; ++i)
		{
			if(input[i]==i+1)
			cout << 2*input[i] <<" ";
			else
			cout << input[i] <<" ";
		}
		cout << endl;
	}
	return 0;
}