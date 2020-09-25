#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
    int *ans = new int[s.length()];
    unordered_map<char, vector<int>> m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]].push_back(i);
    }

    int n_odd = 0;
    for (int i = 0; i < m.size(); i++)
    {
        if (m[i].size() % 2 != 0)
            n_odd++;
    }
    if (n_odd >= 2)
    {
        cout << "-1";
        return;
    }
 int start = 0;
 int end = s.length()-1;
 for (int i = 0; i < m.size(); i++)
 {
     vector<int> k =  m[i];
     for(int j = 0; j < k.size(); j+=2){
         if((k.size()-j)==1){
             ans[s.size()/2] = k[j]+1;
             continue;
         }
         ans[start] = k[j]+1;
         ans[end] = k[j+1]+1;
         start++;
         end--;
     }
     
 }
 

    for (int i = 0; i < s.length(); i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{

    int n;
    cin >> n;
    while (n--)
    {
        string input;
        cin >> input;
        solve(input);
        cout << endl;
    }
    return 0;
}