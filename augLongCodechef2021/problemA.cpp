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
	while(testcases--)
	{
		int g1,s1,b1,g2,s2,b2;
		cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;

		int t1 = g1 + s1 + b1;
		int t2 = g2 + s2 + b2;

		if(t1>t2)
			cout << 1 << endl;
		else
			cout << 2 << endl;
		
	}
	return 0;
}