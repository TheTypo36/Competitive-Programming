#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int d1,v1,d2,v2,p;
	cin >> d1 >> v1 >> d2 >> v2 >> p;
	int i =1, med = 0;
	while( med <p){
		if(i>=d1){
			med +=v1;
		}
		if(i>=d2){
			med+=v2;
		}
		i++;
	}
	cout << i-1 << endl;
}