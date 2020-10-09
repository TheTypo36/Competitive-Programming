#include <bits/stdc++.h>
using namespace std;
int minCost(int *input, int n, int k, int l){
	int Finalans = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		int curr_pivot = input[i], curr_cost = 0;
		int inc=0;
		int dec = 0 ;
		for (int j = 0; j < n; ++j)
		{
			if(input[j] <= curr_pivot){
				inc += (input[j]-curr_pivot);
			}else{
				dec +=(curr_pivot-input[j]) ;
			}
		}
		if( dec > inc){
				continue;
		}else{
			curr_cost = (dec*k)+((inc-dec)*l);
			Finalans = min(Finalans,curr_cost);
		}
	}
	return Finalans;
}
int main(){
	int n;
	cin >> n;
	int k ,l;
	cin >> k >> l;
	int *input = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}
	cout << minCost(input,n,k,l) << endl;
return 0;
}