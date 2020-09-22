#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
   cin >> n;
   int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int f,s,t,c=0;
        cin >> f>> s>>t;
        if(f==1)
        c++;

        if(s==1)
        c++;
        if(t==1)
        c++;

        if(c>=2)
            ans++;
    }
    cout << ans << endl;
    
}