#include <bits/stdc++.h>
using namespace std;
double trimMean(vector<int>& arr) {
	sort(arr.begin(),arr.end());
    int l = arr.size();
	double remain =(0.05*l);
   // cout << remain << endl;
    double start = remain;
	double end = arr.size() - remain;
	double sum = 0;
	for (int i = start; i < end; ++i)
	{
		sum += arr[i];
	}
	double d = (end - start);
	double ans = sum/d;
	return ans;
	cout << 
}
//[1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
int main(){
	int n;
	cin >> 
	cout << trimMean(n);
}