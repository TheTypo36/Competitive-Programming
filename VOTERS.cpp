#include <bits/stdc++.h>
using namespace std;

int main()
{

    int size1, size2, size3;
    cin >> size1 >> size2 >> size3;
    int total = size1 + size3 + size2;
    int *input = new int[total];
    for (int i = 0; i < total; i++)
    {
        cin >> input[i];
    }
    map<int, int> freq;
    for (int i = 0; i < total; i++)
    {
        freq[input[i]]++;
    }
    vector<int> ans;
    map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
    {
      //  cout << "key -> " << it->first << " value -> " << it->second << endl;
        if (it->second >= 2)
        {
            ans.push_back(it->first);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}