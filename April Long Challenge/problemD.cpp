#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	 int testcases;
	 cin >> testcases;
	 while(testcases--){
	 	long long int n = 0;
	 	cin >> n;
	 		
	 	long long int sum = (n/4)*44;
	 	long long int rem = n%4;
	 	if(n>=4)
	 	{
	
		 	if(rem == 0){
		 		sum+= 16;
		 	}else if(rem == 1){
		 		sum+=32;
		 	}else if(rem == 2){
		 		sum+=44;
		 	}else if(rem == 3){
		 		sum+=55;
		 	}
	 		cout << sum << endl;
	 
	 	}else{
	 		if(rem==1)
	 			sum = 20;
	 		else if(rem == 2)
	 			sum = 36;
	 		else if(rem == 3)
	 			sum = 51;
	 		cout << sum << endl;
	 	}
	 	
	 }
	 
}