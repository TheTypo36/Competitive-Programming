#include <bits/stdc++.h>
typedef int ll;
using namespace std;

void test_case(int * input, int n,int k ){
	
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum+=input[i];
	}
	for(int i = 0; i < n; ++i)
		{
			if(input[i] < k){
				cout << i + 1 << endl;
				return;
			}
			if(i < n-1)
			input[i+1]+=(input[i] -  k);
			
		}
		int ans = 0;
		ans = (sum/k) +1;
		cout << ans << endl;
		return;
}


int main()
{
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		int n, k;
		cin >> n >> k;
		int* input = new int[n];
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> input[i] ;
			//sum+=input[i];
		}
		//int ans = (sum/k) + 1; 
		//cout << ans << endl;
		test_case(input, n, k);
	}
	return 0;
}