#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int *prices = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    int max_profit = 0;
    for (int i = 0; i < n; i++)
    {
        int cp = prices[i];
        for (int j = i+1; j < n; j++)
        {
            int profit = prices[j] - cp;
            max_profit=max(max_profit,profit);
        }
        
    }
    cout << max_profit << endl;
    
}