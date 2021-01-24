#include <bits/stdc++.h>
using namespace std;

int main(){
	int testcases;
	cin >> testcases;
	while(testcases--){
		string s;
		string t;
		cin >> s >> t;
		int finallength = lcm(s.length(),t.length());
		//cout << finallength <<endl;
		string p = t;
		while(p.length()<finallength){
			p+=t;
		}
		//cout << p << endl;
		string q = s;
		while(q.length()<finallength){
			q+=s;
		}
		//cout << q << endl;
		if(p==q){
			cout << q << endl;
		}else{
			cout << -1 << endl;
		}
	}
}