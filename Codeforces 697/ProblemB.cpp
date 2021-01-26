#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcases;
	cin >> testcases;
	while(testcases--){
		int n;
		cin >> n;
		int We_have_twentyTwenties = n / 2020;
		int twenty_twentYone_we_need_to_change = n % 2020;
		if(We_have_twentyTwenties>=twenty_twentYone_we_need_to_change){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}
