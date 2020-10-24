#include <bits/stdc++.h>
using namespace std;



int knapsackSpaceOptimised(int* weight, int * value, int n, int capacity)
{
	int* dp1 = new int[capacity + 1]();
	int* dp2 = new int[capacity + 1]();

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= capacity; ++j)
		{
			if(weight[i-1] > j){
				dp2[j] = dp1[j];
			}else{
				int option1 = value[i-1] + dp1[j-weight[i-1]];
				int option2 = dp1[j];
				dp2[j] = max(option1, option2);
			}
		}
		for(int j = 0;  j<=capacity ; j++)
		{
			dp1[j]=dp2[j];
			dp2[j]=0;
		}
	}
	int ans = dp1[capacity];
	delete [] dp1;
	delete [] dp2;
	return ans;

}
int knapsackTimeOptimised(int* weight, int* value, int n, int capacity)
{
	int** dp = new int*[n+1];
	for(int i = 0 ; i <= n; i++)
	{
		dp[i] = new int[capacity+1];
		for (int j = 0; j <= capacity; ++j)
		{
			dp[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1 ; j <= capacity; j++){
			if(weight[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				int option1 = value[i-1] + dp[i-1][j-weight[i-1]];
				int option2 = dp[i-1][j];
				dp[i][j] = max(option1, option2);
			}
		}
	}
	int ans = dp[n][capacity];
	for (int i = 0; i <= n; ++i)
	{
		delete dp[i];
	}
	delete [] dp;
	return ans;

}


int knapsack_recur(int* weight, int * value, int n, int capacity)
{
	if(capacity == 0 || n == 0)
	{
		return 0;
	}

	if(weight[0] > capacity){
		return knapsack_recur(weight+1,value+1,n-1,capacity);
	}else{
		int option1 = value[0] + knapsack_recur(weight+1,value+1,n - 1,capacity - weight[0]);
		int option2 = knapsack_recur(weight+1, value+1, n -1 , capacity);
		return max(option2,option1);
	}
}
int main(){
	int n;
	cin >> n;
	int * weight = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> weight[i];
	}
	int * value = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> value[i];
	}
	int capacity;
	cin >> capacity;
	cout << knapsackSpaceOptimised(weight,value,n, capacity) << endl;
}