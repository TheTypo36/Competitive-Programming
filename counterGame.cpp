#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string counterGame(long n) {
    int i = 0;
    while(n!=1){
        if((n&(n-1))==0){
            n = n >> 1;

        }else{
            int m = n;
            int c = 0;
            while(m!=1){
                m = m >> 1;
                c++;
            }
            int z = (1 << c);
            n = n - z ;
        }
        i++;


    }
    if(i%2==0){
        return "Richard" ;
    }else{
        return "Louise" ;
    }


}
int main()
{
	int testcases;
	cin >> testcases;
	while(testcases--)
	{
		ll n;
		cin >> n;
		cout <<counterGame(n) << endl;
	}
	return 0;
}