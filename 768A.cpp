#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int *input = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int mininum = INT_MAX;
    int maximum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (mininum > input[i])
            mininum = input[i];
        if (maximum < input[i])
            maximum = input[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (input[i] > mininum && input[i] < maximum)
            count++;
    }
   // cout << maximum << endl;
    //cout << mininum << endl;
    cout << count << endl;
}