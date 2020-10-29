#include <bits/stdc++.h>
using namespace std;

int minAbsoluteDiff(int arr[], int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	sort(arr,arr+n);
    int diff = INT_MAX;
    for(int i = 0; i < n; i++){
        if(i+1< n){
	        int curr_diff = abs(arr[i] - arr[i+1]);
			diff = min(curr_diff,diff);           
        }
    }
	return diff;
}

int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	cout<< minAbsoluteDiff(input,size) << endl;
	
	return 0;

}