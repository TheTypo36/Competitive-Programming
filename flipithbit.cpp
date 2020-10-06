#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int i;
	cin >> i;
	int mask = 1 << i;
	int z = n^mask;
	cout << z << endl;
}