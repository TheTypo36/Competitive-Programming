#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
   cin >> n;
    for (int i = 2; i < n-1; i++)
    {
        int a = n-i;
        int b = i;
        if(a%2==0&&b%2==0){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << " NO" << endl;
    return 0;
    
}