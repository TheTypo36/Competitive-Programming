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
		int n;
		cin >> n;
		vector<int> arr(n,0);
		unordered_map<int,int> freq;
		for (int i = 0; i < n; ++i)
		{	
			cin >> arr[i];

		}
		for (int i = 0; i < n; ++i)
		{
			freq[arr[i]]++;
		}

			int UniquePoint = 0;
		for(unordered_map<int,int>::iterator it = freq.begin(); it!= freq.end(); it++){
			if(it->S==1){
				UniquePoint++;
			}else{
				UniquePoint += min(it->S, (it->F-1));
			}
		}
		
		


		cout << UniquePoint << endl;
	}
	return 0;
}