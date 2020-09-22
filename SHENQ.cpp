#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &input, int n)
{

    if (n == 0)
        return;

    if (input[n - 1] % 2 == 0 && input[n - 2] % 2 == 0)
    {
        int replacement = input[n - 1] + input[n - 2] + 1;
        input[n - 2] = replacement;
        input.pop_back();
    }
    else if (input[n - 1] % 2 != 0 && input[n - 2] % 2 != 0)
    {
        int replacement = input[n - 1] + input[n - 2];
        input[n - 2] = replacement;
        input.pop_back();
    }
    solve(input, n - 1);
}
int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        /* code */

        int n;
        cin >> n;
        vector<int> input(n);
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        solve(input, n);
        cout << input.size() << endl;
        for (int i = 0; i < input.size(); i++)
        {
            cout << input[i] << " ";
        }
        cout << endl;
    }
}