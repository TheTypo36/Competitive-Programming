#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
   cin >> n;
    int * input = new int[n+1];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    unordered_set<int> s;
    for (int i = 1; i < n-1; i++)
    {
        s.insert(input[i]);
    }
    cout << s.size() << endl;
    
}