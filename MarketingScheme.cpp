#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool pack(int l, int r){
	int low = 1;
	int high = (int) pow(10,7);
	while(low<=high){
		ll mid = low;
			 int f1 = l % mid;
			 int f2 = r % mid;
			 int com = (mid+1)/2;
			if(f1 >= com && f2>= com){
				return true;
			}
		low++;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		int l , r;
		cin >> l >> r;
		bool ans = pack(l,r);
	
		if(ans == false){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
	}
	return 0;
}