#include <bits/stdc++.h>
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
		int n;
		cin >> n;
		int queries;
		cin >> queries;
		ll* seq = new ll[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> seq[i];
		}
		int l = 1;
		for(int i = 1; i < n; i++)
		{
			l += (seq[i-1]!=seq[i])?1:0;
		}
		while(queries--){
			int x;
			ll y;
			cin >> x >> y;
			x--;
			if(x!=0){
				l -= (seq[x]!=seq[x-1])?1:0;
				l += (y!=seq[x-1])?1:0;
			}
			if(x!=n-1){
				l -= (seq[x]!=seq[x+1])?1:0;
				l += (y!=seq[x+1])?1:0;
			}
			seq[x] = y;
			cout << l<< endl;
		}
	}
	return 0;
}