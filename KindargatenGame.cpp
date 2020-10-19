#include <bits/stdc++.h>
using namespace std;

int solve(int *input, int n, vector<string> &v){
	if(n == 0){
		v.push_back("");
		return 1;
	}
	if( n == 1)
	{
		v.push_back(input[0]);
		return 1;
	}
	int size = solve(input+1,n-1,v);
	for (int i = 0; i < size; ++i)
	{
		v.push_back(v[i]+input[0]);
	}
	return 2*size;
}
int main(){
	int n,m;
	cin >> n >> m;
	set<int> s;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		s.insert(a);
		s.insert(b);
	}
	int * input  = new int[s.size()];
	for (int i = 0; i < s.size(); ++i)
	{
		input[i] = s[i];
	}
	std::vector<string> v;
	int size = solve(input,s.size(),v);
	cout << size - n << endl; 
}