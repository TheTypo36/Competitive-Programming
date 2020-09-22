#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, target;
    cin >> n >> target;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int sum = input[i];
        vector<int> ans;
        ans.push_back(input[i]);
        for (int j = i + 1; j < n; j++)
        {
            if (sum + input[j] > target)
                break;
            sum += input[j];
            ans.push_back(input[j]);
            if (sum == target)
            {
                cout << "true" << endl;
                for (int k = 0; k < ans.size(); k++)
                {
                    cout << ans[k] << " ";
                }
                return 0;
            }
        }
    }
    if (input[n - 1] == target)
    {
        cout << "true" << endl;
        cout << input[n - 1] << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}