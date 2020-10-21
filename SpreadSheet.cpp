#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<int> minRow(n, 0);
	vector<int> row1(m, 0);
	vector<int> row2(m, 0);
	vector<int> dp1(m, 0);
	vector<int> dp2(m, 0);
	minRow[0] = 0; 

	for (int i = 0; i < m; ++i)
	{
		cin >> row1[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> row2[i] ;
	}
	for (int i = 0; i < m; ++i)
	{
		if(row2[i] >= row1[i]){
				dp2[i] = 0;
			}else{
				dp2[i] = 1;
			}
	}

	int minvalue = INT_MAX;
		for (int j = 0; j < m; ++j)
		{
			minvalue = min(dp2[j],minvalue);
		}
		minRow[1] = minvalue;
	for (int i = 2; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			row1[j] = row2[j];
			dp1[j] = dp2[j];
		}

		for (int j = 0; j < m; ++j)
		{
			cin >> row2[j];
		}
		
		for (int j = 0; j < m; ++j)
		{
			if(row2[j] >= row1[j]){
				dp2[j] = dp1[j];
			}else{
				dp2[j] = i;
			}
		}
		 minvalue = INT_MAX;
		for (int j = 0; j < m; ++j)
		{
			minvalue = min(dp2[j],minvalue);
		}
		minRow[i] = minvalue;
		
	
	}
	int query;
	cin >> query;
	while(query--)
	{
		int li , ri;
		cin>> li >> ri;
		int limit = minRow[ri-1];
		if(limit < li){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
}