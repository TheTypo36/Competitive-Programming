#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define F first
#define S second 
typedef long long ll;

uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    uint32_t i = 31;
    while(n>0){
        uint32_t bit = n & 1 ;
        ans = ans+ pow(2,i) * bit;
        n = n >> 1;
        i--;
    }
    return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	uint32_t n;
	cin >> n;
	cout << reverseBits(n) << "\n";
	
}