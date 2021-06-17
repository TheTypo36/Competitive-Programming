#include <bits/stdc++.h>
using namespace std;
//naive approach
typedef long long ll;
int ordrOfNcube(vector<int> arr, int n){
    int sum = 0;
    for(int x = 0 ; x < n; x++){
        for(int y = 0; y < n; y++){
            if(x==y){
                continue;
            }
            for(int z = 0; z< n; z++){
                if(x==z||y==z){
                    continue;
                }
                int curr = abs(arr[x]-arr[y])+abs(arr[y]-arr[z])+abs(arr[z]-arr[x]);
                if(curr > sum){
                    sum = curr;
                }
            }
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int testcase;
    cin >> testcase;
    while(testcase--){
        ll n;
         cin >> n;
         vector<ll> arr(n,0);
         for(int i = 0; i < n; i++){
             cin >> arr[i];
         }
         sort(arr.begin(),arr.end());
         ll x = arr[0];
         ll  y = arr[1];
         ll z = arr[n-1];
         ll sum = (z-x)+(z-y)+(y-x) ;
         ll currSum = 0;
         for(ll i = 2; i < n-1; i++){
             currSum = (z-x)+(z-arr[i])+(arr[i]-x);
             sum = max(sum,currSum);
         }
         cout << sum << endl;
         //cout << "naiveApproach:" << ordrOfNcube(arr,n) << endl;
    }
}
