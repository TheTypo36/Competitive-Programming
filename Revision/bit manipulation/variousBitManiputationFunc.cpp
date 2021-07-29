#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MP make_pair
#define F first
#define S second
typedef long long ll;

//time which id O(no of bits) 
int CountBit(int n){
	int count = 0;
	while(n>0){
		
		count +=(n&1);

		n>>=1;
	}
	return count;
}
//how to get the ith bit
int getIthBit(int n, int i){
	int mask = 1 << i;
	int bit = n & mask;
	return (bit==0)?0:1;

}
//more efficient hack called n & (n-1).
//so doing n & (n-1) remove the last set bit , time = O(no. of set bit)
int CountBitAdvance(int n){

	int count = 0;
	while(n>0){
		count++;

		n &=(n-1);
	}
	return count;
}
//function of setting Ith bit
int setIthBit(int n, int i){
	int mask = 1 << i;

	return n|mask;
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << "set bits are" << CountBitAdvance(n) << endl;
	cout << "ith bit is:" << getIthBit(n, 3) << endl;
	cout << "setIth Bit:" << setIthBit(n,1) << endl;
}