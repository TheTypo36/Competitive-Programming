#include <bits/stdc++.h>
using namespace std;

void Max_perimeter(int * side, int n){
	int start = n-3;
	int mid = n-2;
	int end = n-1;
	while(side[start] + side[mid] <= side[end]){
		
		if(start<0){
		
			cout << -1 << endl;
		}
		start--;
		end--;
		mid--;
	}
	cout << side[start] << " " << side[mid] << " "<< side[end]<< endl;


}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	int * side =new int[n];
	for(int i= 0 ; i < n; i++){
		cin >> side[i];
	}
	sort(side,side+n);
	 Max_perimeter(side,n);
}