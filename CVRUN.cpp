#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		int n, k ,x , y;
		cin >> n >> k >> x >> y;
		int round = 0;
		while(true){
			if(x==y){
				cout << "YES" << endl;
				break;
			}
			if(round==20000){
				cout << "NO" << endl;
				break;
			}
			x=(x+k)%n;
			round++;
		}
		
	}
	return 0;
}