#include <bits/stdc++.h>
using namespace std;
int lcs_recur(int *arr, int size){
	int* strg = new int[size+1]();
	strg[0] = 0;
	strg[1] = 1;
	for (int i = 2; i <=size; ++i)
	{
		for (int j = i-2; j >=0; j--)
		{
			if(arr[j]<=arr[i-1]){
				int length=  1+ strg[j+1];
				strg[i] = max(strg[i],length);
			}
		}
		
	}
	int output = 0;
	for (int i = 0; i <=size; ++i)
	{
		
		if(strg[i]>output){
			output = strg[i];
		}
	}
	
	delete [] strg;
	return output;
}
int main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
	    int n;
	    cin >> n;
    	int *arr = new int[n];
	    for (int i = 0; i < n; ++i)
	    {
		    cin >> arr[i];
	    }
	    cout << lcs_recur(arr,n) << endl;
    }
}