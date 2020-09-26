#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {

        int n;
        cin >> n;
        bool c = true;
        int* input = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        if(n>2){
            cout << "YES" << endl;
        }
        for (int i = 0; i < n; i++)
        {
            int k = i+1;
            if(input[i]%k!=0||input[i] < 0){
                    cout << "NO" << endl;
                    c = false;
            }
        }
        if(c)
        cout << "YES" << endl;
        
    }
}