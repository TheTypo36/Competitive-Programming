#include <bits/stdc++.h>
using namespace std;
int MOD = (int)pow(10,9) + 7;
long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
	long oneCount = 1;
	long nonOneCount = 0;
	for (long i = 1; i < n; ++i)
	{
		long prevOneCount = oneCount;
		oneCount = (nonOneCount * (k - 1)) % MOD;
		nonOneCount = (prevOneCount + ((k-2)*(nonOneCount))%MOD)%MOD;
	}
	if(x == 1){
		return oneCount;
	}else{
		return nonOneCount;
	}
}
int main(){
	int n;
	cin >> n;
	int k , x;
	cin >> k >> x;
	cout << countArray(n, k , x) << endl;
}