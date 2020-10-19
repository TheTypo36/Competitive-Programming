#include <bits/stdc++.h>
using namespace std;

double distance(double* x,double* y, int i, int j)
{
	double diff1 = x[i] - x[j];
	double diff2 = y[i] - y[j];
	double ans = sqrt((diff1*diff1) + (diff2 * diff2));
	return ans;

}
double minimalHappiness(double* x, double* y, double* happiness, int n)
{
	double * dp = new double[n];
	for (int i = 0; i < n; ++i)
	 {
	 	dp[i] = -1e9;
	 } 
	 dp[0] = 0;
	 for (int i = 0; i < n; ++i)
	 {
	 	dp[i] += happiness[i];
	 	for (int j = i + 1; j < n; ++j)
	 	{
	 		double dis = distance(x,y,i,j);
	 		dp[j] = max(dp[j], dp[i] - dis);
	 	}
	 }
	 double ans = dp[n - 1];
	 delete [] dp;
	 return ans;
}
int main(){
	int n;
	cin >> n;
	double* x = new double[n];
	double* y = new double[n] ;
	double* happiness = new double[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i] >> happiness[i] ;
	}
	cout << fixed;
	cout <<std::setprecision(6) << minimalHappiness(x,y,happiness,n) << endl;
	delete [] x;
	delete [] y;

	return 0;
}