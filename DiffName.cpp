#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
   string names;
	getline(cin, names);
	unordered_map<string, int> m1;
	stringstream iss(names);
    string temp;

	while(iss>>temp){
		m1[temp]++;
	}
    unordered_map<string,int>::iterator it;
    int c = 0;
    for(it = m1.begin(); it!=m1.end(); it++){
        if(it -> second > 1)
        {
            cout << it -> first <<" " << it -> second << endl;
            c++;
        }
    }
    if(c==0){
        cout << -1 << endl;
    }
    
}