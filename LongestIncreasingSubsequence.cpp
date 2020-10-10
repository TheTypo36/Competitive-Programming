#include <bits/stdc++.h>
using namespace std;
int lcs_recur(int *arr, int size){
	if(size == 0){
		return 0;
	}
	int* strg = new int[size]();
	strg[0] = 1;
	for (int i = 1; i <size; ++i)
	{
		strg[i] = 1;
		for (int j = i-1; j >=0; j--)
		{

			if(arr[j]<=arr[i]){
				int length=  1+ strg[j];
				strg[i] = max(strg[i],length);
			}
		}
		
	}
	int output = 0;
	for (int i = 0; i <size; ++i)
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