#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> box(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> box[i];
	}
	sort(box.begin(),box.end());
	int sum = box[0];
	int cost = 0;
	for (int i = 1; i <k; ++i)
	{
		cost = cost + ((i*box[i]) - sum);
		sum += box[i];
	}
	
	int ans = cost;
	int newCost = cost;
	for(int i = k; i < n; i++)
	{
		sum = sum - box[i-k];
		newCost = newCost + ((k-1)*box[i-k]) + ((k -1) * box[i]) - (2 * sum);
		ans = min(newCost,ans);
		sum += box[i];
		
	}
	cout <<ans << endl;

}