#include <bits/stdc++.h>
using namespace std;
int kadanes_algo(int * arr, int n){
    int curr_ele = 0, best_so_far=0;
    for (int i = 0; i < n; i++)
    {
         curr_ele+=arr[i];
        if(curr_ele>best_so_far){
            best_so_far = curr_ele;
        }
        if(curr_ele<0){
            curr_ele = 0;
        }
    }
    return best_so_far;
}
int main(){

    int n;
   cin >> n;
    int * arr = new int[n] ;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }
    cout << kadanes_algo(arr,n) << endl;
    
}