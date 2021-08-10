#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define F first
#define S second
typedef long long ll;

using namespace std;

void solution2(int n, int p, int k){
		vector<pair<int,int>> v(n);
		for(int i = 0 ; i < n; i++){
			v[i].F = i % k;
			v[i].S = i;
		}
		sort(v.begin(), v.end());
		

		int days = 0;
		for(int i = 0; i < n ; i++){
			days++;
			if(v[i].S==p)
				break;
		}
		cout << days << endl;
	
}
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
		int p, k;
		cin >> p >> k;
		//cout << "sol1: " << endl;
		if(p==0){
			cout << 1 << endl;

		}else if(p%k==0){
			cout << (p/k)+1 << endl;
		}
		else{
			int rem = 1;
			int days = 1 + ((n-1)/k); 
			while(true){
				int num = rem;
				int count = 1;
				int flag = 0;
				while(num < n){
					if(num==p){
						flag = 1;
						break;
					}
					num+=k;
					if(num > n){
						break;
					}
					count++;
				}
				if(flag==1){
					days+=count;
					cout << days << endl;
					break;
				}
				days+=count;
				rem++;
			}
		}

		
	}
	return 0;
}