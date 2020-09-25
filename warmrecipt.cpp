#include <bits/stdc++.h>
using namespace std;
int main()
{

    // Write your code here
    int n;
    cin >> n;
    int *arrival = new int[n];
    int *departure = new int[n];
    for (int index = 0; index < n; index++)
    {
        cin >> arrival[index];
    }
   for (int i = 0; i < n; i++)
   {
       cin >> departure[i];
   }
   sort(arrival,arrival+n);
   sort(departure,departure+n);
   int j = 0;
   int chairs = 0;
   for (int i = 0; i < n; i++)
   {
       if(arrival[i]<=departure[j]){
           chairs++;
           continue;
       }
       j++;
   }
   cout << chairs << endl;
   
   
}