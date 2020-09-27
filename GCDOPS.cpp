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
        int* input = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        int *myarr = new int[n];
        for (int i = 0; i < n; i++)
        {
            myarr[i] = i+1;
        }
        int flag=0;
        for (int i = 0; i < n; i++)
        {
           if(myarr[i]!=input[i]&&myarr[i]%input[i]!=0){
               cout << "NO" << endl;
            flag=1;
            break;
           }
        }
        if(flag==0)
        cout<<"YES"<<endl;
        
        
    }
}