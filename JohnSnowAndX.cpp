#include <bits/stdc++.h>
using namespace std;
#define size 1024
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, x;
	cin >> n >> k >> x;
	vector<int> rangers(size, 0);
	for (int i = 0; i < n; ++i)
	{
		int strength;
		cin >> strength;
	 	rangers[strength]++;
	}
	vector<int> ans(size, 0);
	while(k--)
	{
		for (int i = 0; i < size; ++i)
		{
			ans[i] = 0;
		}
		int sum = 0;
		int j;
		for ( j = 0; j < size; ++j)
		{
			int units = rangers[j];
			int odd ;
			int even;
				if(sum % 2 == 0){
					 odd = (units+1)/2; 
					even = units - odd;
				}else{
					 odd = (units/2);
					even = units - odd;
				}	
			int index = x ^ j;
			ans[index] += odd;
			ans[j] += even;
			sum +=units;
		
			}
			for(int i = 0 ; i < size; i++)
			{
				rangers[i] = ans[i];
			}
	}

	for (int i = size-1; i >=0 ; --i)
	{
		if(rangers[i] != 0){
			cout << i << " ";
			break;
		}	
	}
	for (int i = 0; i < size; ++i)
	{
		if(rangers[i] != 0){
			cout << i << endl;
			break;
		}
	}

	
}