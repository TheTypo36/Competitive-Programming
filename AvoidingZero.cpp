#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void test_case(int * input, int n)
{
	int sum = 0;
	int zero = 0 ;
	for (int i = 0; i < n; i++)
	{
		if(input[i] == 0){
			zero++;
		}
		int j = i;

		while(j+1<n&&sum+input[j]==0){
			j++;
		}
		if(i+1 < n ){
		int swap = input[j];
			input[j] = input[j+1];
			input[j+1] = swap ;
		}
		
	}
	if(zero==n){
		cout << "NO" ;
		return;
	}
	if(sum!=0);
	cout << "YES" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << input[i] << " ";
		
	}

	

}
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
		test_case(input ,n);
		cout << endl;
	}
	return 0;
}