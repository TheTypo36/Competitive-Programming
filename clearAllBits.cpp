#include <bits/stdc++.h>
using namespace std;
int clearAllBits(int n, int i){
   
    int mask =((1 << i)-1);
    int z = (n&mask);
    return z;
}


int clearAllBitsL(int n, int i){
	int mask = ~((1 << (i+1))-1);
	return (n&mask);
}
int main(){
	int n;
	cin >> n;
	int i;
	cin >> i;
	cout << clearAllBits(n,i) << endl;
	cout << clearAllBitsL(n,i) << endl;
}