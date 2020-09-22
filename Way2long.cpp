#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
   cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if(s.length()>10){
            int str;
            int l = s.length()-2;
            s=s[0]+to_string(l)+s[s.length()-1];
            cout << s << endl;
        }else{
            cout << s << endl;
        }
    }

}