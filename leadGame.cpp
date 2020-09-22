#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    int p1s = 0, p2s = 0, maxlead = INT_MIN;
    bool winner = false;
    while (t--)
    {
        int p1, p2;
        cin >> p1 >> p2;
        p1s += p1;
        p2s += p2;
        if (p1s > p2s)
        {
            int lead = p1s - p2s;
            if (lead > maxlead)
            {
                maxlead = lead;
                winner = true;
            }
        }
        else if (p1s < p2s)
        {
            int lead = p2s - p1s;
            if (lead > maxlead)
            {
                maxlead = lead;
                winner = false;
            }
        }
    }
    if (winner)
    {
        cout << 1 <<" "<< maxlead << endl;
    }
    else
    {
        cout << 2 <<" "<< maxlead << endl;
    }
}
/*
5
140 82
89 134
90 200
112 106
88 90
*/