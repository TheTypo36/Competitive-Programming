#include <bits/stdc++.h>
using namespace std;

int kadanes_improvise(int* input, int n){
    int curr_neg = 1, curr_pos = 1, best_so_far = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(input[i] == 0){
            curr_neg = 1;
            curr_pos = 1;
            if(best_so_far < curr_pos ){
                best_so_far = curr_pos; 
            }
        }
        else if(input[i] > 0){
            curr_neg = min(1,input[i]*curr_neg);
            curr_pos = curr_pos * input[i];
            if(curr_pos > best_so_far){
                best_so_far = curr_pos;
            }
        }else{
            int temp = curr_pos;
            curr_pos = max(1,input[i]*curr_neg);
            curr_neg = temp*input[i];
            if(curr_pos > best_so_far){
                best_so_far = curr_pos;
            }
        }
    }
    return best_so_far;
}
int main(){

    int n;
   cin >> n;
    int* input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    cout << kadanes_improvise(input,n) << endl;
    
}