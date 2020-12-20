#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	string s,p;
	cin >> s >> p;
	for(int i = 0; i <= s.length()-p.length(); i++){
		bool ans = true;
		for(int j = 0; j < p.length();j++){
			if(s[i+j] != p[j]){
				ans = false;
				break;
			}
		}
			if(ans == true){
				cout << "Yes" << endl;
				return 0;
			}
	}
	cout <<"NO" << endl;
	return 0;
}