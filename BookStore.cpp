#include <bits/stdc++.h>
using namespace std;

int minPriceToPay(int* cost, int n){
	int totalPrice = 0 ;
	int i = 0;

	while(i+3<=n){
		int minIndex = 0, minValue = INT_MAX;
		for (int j = i; j <i+3; ++j)
		{
			if(cost[j] < minValue){
				minValue = cost[j];
				minIndex = j;
			}
		}

		for (int j = i; j < i+3; ++j)
		{
			if( j != minIndex){
				totalPrice +=cost[j];
			}
		}
		//cout << "sum: " << totalPrice << endl;
		//cout << "minIndex :" << minIndex << endl;
		//cout << "minValue : " << minValue << endl;
		i = i + 3;
	}
	while(i<n){
		totalPrice +=cost[i];
		i++;
	}
	return totalPrice;
}
int main(){
	int n;
	cin >> n;
	int* input = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}
	sort(input,input+n, greater<int>());
	cout << minPriceToPay(input, n);
	delete [] input;
	return 0;
}