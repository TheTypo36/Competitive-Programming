#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < v.size(); ++i)
	{
		cin >> v[i]; 
	}
	int sumOfEven = 0, sumOfOdd = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if((i+1)%2==0){
			sumOfOdd+=v[i] ;
		}else{
			sumOfEven+=v[i];
		}
	}
	cout << 2*min(sumOfEven,sumOfOdd) << endl;
}