#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
   cin >> n;
    while (n--)
    {
        int grade;
        cin >> grade;
        if(grade < 38){
            cout << grade << endl;
        }else if((grade+1)%5==0){
            cout << grade+1 << endl;
        }else if((grade+2)%5==0){
            cout << grade+2 << endl;
        } else{
            cout << grade << endl;
        }
    }

}