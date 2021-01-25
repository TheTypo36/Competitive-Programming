#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	while(testcase--){
		string s;
		cin >> s;
		int l = s.length();
		
		bool checkUpper = false; 
		bool specialChecker = false; 
		bool digitChecker = false; 

		for(int i =1 ; i < l-1; i++ ){
			if(s[i]>=65 && s[i] <= 90){
				checkUpper = true;
			}
			if(s[i] =='@'||s[i]== '#'||s[i]== '%'||s[i]== '&'||s[i]== '?'){
				specialChecker = true;
			}
			if(s[i] >=48 && s[i] <=57 ){
				digitChecker = true;
			}
		}
		bool checklower = false;
		for (int i = 0; i < l; ++i)
		{
			if(s[i] >=97 && s[i] <= 122){
				checklower = true;
			}	
		}
		int first = (int) s[0];
		int last = (int) s[l-1];
		if(checklower == false||checkUpper == false || digitChecker == false|| specialChecker == false){
			cout << "NO" << endl;
		}
		else if(l<10){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
	}
}