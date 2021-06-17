#include <bits/stdc++.h>
using namespace std;
int main() {
     #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

     ios_base::sync_with_stdio(false);
     cout.tie(NULL);
     
    int n;
    cin >> n;
    for(int i = 10 ; i >= 0; i--){
        if(n%i==0){
            cout << i << endl;
            return 0;
        }
    }
    
}
