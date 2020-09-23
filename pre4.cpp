#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
   cin >> n;
    int* villages = new int[n];
    for (int index = 0; index < n; index++)
    {
        int population = 0;
        cin >> population;
        villages[index] = population;
    }
    int low = 0, high = n -1;
    while(high>low){
        int totalPoplutaion = villages[low]+villages[high];
        int groups = totalPoplutaion/10;
        int peopleLeft = totalPoplutaion%10;
        cout << groups << " " << peopleLeft << endl;
        low++;
        high--;
    }
   
    
}