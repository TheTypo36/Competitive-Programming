#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	
	int n;
	cin >> n;
	int* input = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i] ;
	}	
	int* out = new int[n];
	for (int i = 0; i < n; ++i)
	{	
		input[i] = input[i] - i;
		if(input[i] < 0) {
			input[i] = 0;
		}
		int t = input[i] / n;
		if((input[i])%n != 0){
			t = t + 1;
		}

		int replace = i+(t*n);
		out[i] = replace;

	}
	int ans = INT_MAX;
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		//cout << "input: " << out[i] << endl;
		if(out[i] < ans){
			ans = out[i] ;
			index = i; 
		}
	}
	cout << index + 1 << endl;
	return 0;
}