#include <bits/stdc++.h>
using namespace std;

int main()
{

    int testcases;
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
        for (int i = 0; i < n; i++)
        {
            if(input[i]==myarr[i]){
                continue;
            }else
            {
                int start = 0;
                int end = n-1;
                if(__gcd(myarr[start],myarr[end])==input[i]){
                    myarr[start] = input[i];
                    myarr[end] = input[i];
                }else{
                    
                }
                
            }
        }
        
        
    }
}