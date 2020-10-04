#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	std::vector<int> v(n,0);
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}
	for (int i = 0; i < n-1; ++i)
	{
		if(v[i]&v[i+1] == 0){

		}
	}
}