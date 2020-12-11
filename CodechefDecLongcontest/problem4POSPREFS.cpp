#include <bits/stdc++.h>
using namespace std;

int main()
{
	 ios_base::sync_with_stdio(false);
	 cout.tie(NULL);
	 int testcase;
	 cin >> testcase;
	 while(testcase--){

		 int n;
		 int k;
		 cin >> n >> k;
		 int i = 0;
		 for( i = 1; i <=k; i++){
		 	cout << i << " ";
		 }
		 int left = n-k;
		 while(left--){
		 	cout << '-' << i << " ";
		 	i++;
		 }
		 cout << endl;
	 }
}