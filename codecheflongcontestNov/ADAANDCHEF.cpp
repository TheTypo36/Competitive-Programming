#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main()
{
	int t;
	cin >> t;
	while(t--){

		int n;
		int* arr = new int[n];
		cin >> n;
		for(int i = 0 ; i < n; i++){
			cin >> arr[i];
		}
		sort(arr, arr+n, greater<int>());
		int burner1 = 0 , burner2 = 0;
		for(int i = 0 ; i < n; i++){
			if(burner2 < burner1){
				burner2 +=arr[i];
			}
			else{
				burner1 += arr[i];
			}

		}
		cout << max(burner1,burner2) << endl;
	}	
}