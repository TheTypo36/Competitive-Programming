#include<bits/stdc++.h>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcases;
	cin >> testcases;
	while(testcases--)
	{

		int n, d;
		cin >> n >> d;
		int * arr = new int[n];
		int risk = 0 , notrisk = 0;
		int days = 0;
		for(int i = 0 ; i < n; i++){
			cin >> arr[i] ;
		}
		for(int i = 0; i < n; i++){
			if(arr[i] <= 9 || arr[i] >=80){
				risk++;
			}else{
				notrisk++;
			}
		}
		while(risk>0){
			days++;
			risk= risk - d;
		}
		while(notrisk>0){
			days++;
			notrisk = notrisk - d;
		}
		cout << days << endl;
		
	}
}
