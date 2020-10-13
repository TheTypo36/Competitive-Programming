#include <bits/stdc++.h>
using namespace std;
int kadanes_algo(int * arr, int n){
	int best = INT_MIN, ending_here = 0;
	for (int i = 0; i < n; ++i)
	{
		ending_here += arr[i];
		best = max(best, ending_here);
		if(ending_here < 0){
			ending_here = 0;
		}
	}
	return best;
}
int MaxSumRect(int ** rect, int n, int m)
{
	int best_sum = INT_MIN;
	for(int left = 0; left < m; left++)
	{
		int arr[n];
			    for (int p = 0; p < n; ++p)
				{
					arr[p] = 0; 
				}
		for (int right = left; right < m; ++right)
		{
			int curr_best_sum = 0;
			
				for (int p = 0; p < n; ++p)
				{
					arr[p] +=rect[p][right];
				}
			
			 curr_best_sum = kadanes_algo(arr, n);
			best_sum = max(best_sum, curr_best_sum);
		}
	}
	return best_sum;
}
int main(){
	int n;                                               
	cin >> n;
	int m;
	cin >> m;
	int **rect = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		rect[i] = new int[m];
		for (int j = 0; j < m; ++j)
		{
			cin >> rect[i][j];
		}
	}
	cout << MaxSumRect(rect, n, m) << endl;
}