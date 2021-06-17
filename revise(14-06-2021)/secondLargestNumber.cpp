#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	unordered_set<int> s;
	for(int i = 0 ; i < n; i++){
		int element;
		cin >> element;
		s.insert(element);
	}
	if(s.size()==0 || s.size() == 1){
		cout << INT_MIN << endl;
		return 0;
	}
	int largest = 0;
	int secondlargest = INT_MIN;
	unordered_set<int>:: iterator it;
	for(it = s.begin() ; it != s.end(); it++){
		int pE = *it;
		if(pE>largest){
			secondlargest = largest;
			largest = pE;

		}else if( pE>secondlargest){
			secondlargest = pE;
		}

	}
	
	cout << secondlargest << endl;
}