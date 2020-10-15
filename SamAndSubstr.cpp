#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
		  //1000000007	
int MOD = (int)pow(10,9)+7;
// Complete the substrings function below.
int substrings(string n) {
    long long sum = n[0] - '0';
    long long Lastsum = n[0] - '0';
    for (int i = 1; i < n.length(); ++i)
    {
        Lastsum = ((Lastsum*10)%MOD + ((n[i] - '0')*(i+1))%MOD)%MOD;
        sum +=Lastsum;
    }
    return sum%MOD;
}

int main(){
	string n;
	cin >> n;
	int sum = substrings(n);
	cout << sum << endl;
}