#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define F first
#define S second
typedef long long ll;

//just find the range and filter character acc to bit represent of each num in range

void filterChars(char* arr, int n){
	int i = 0;
	while(n!=0){
		int bit = n & 1;
		if(bit == 1){
			cout << arr[i];
		} 
		i++;
		n=n >> 1;
	}
}
void generateSubset(char* arr){
	//generate range from 0 to 2^n-1
	int length = strlen(arr);
	int range = 1 << length ;
	for(int i = 0 ; i < range; i++){
		filterChars(arr, i);
		cout << endl;
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	
	
	char arr[1000000];

	cin >> arr;
	generateSubset(arr);




}
