#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input, input + n);
    int c = 0;
    while (n != 1)
    {
        if (c % 2)
        {
            input[0] = 0;
            input = input + 1;
        }
        else
        {
            input[n - 1] = 0;
        }
        n--;

        c++;
    }

    cout << input[0] << endl;
    delete[]input;
}