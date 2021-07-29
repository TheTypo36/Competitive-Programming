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
		int a, b, c;
		cin >> a >> b >> c;

		int right = 0, left=0;
		if(a==0){
			left++;
		}else{
			right++;
		}
		if(b==0)
			left++;
		else
			right++;

		if(c==0)
			left++;
		else
			right++;

		if(left >= 1 && right >= 1){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
		
	}
	return 0;
}