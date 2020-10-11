#include<bits/stdc++.h>
using namespace std;
int longestBitonicSubarray(int *arr, int size) {
	int* dec = new int[size]();
	int* inc = new int[size]();
	dec[size-1] = 1;
	inc[0] = 1;
	for (int i = 1; i < size; ++i)
	{
		inc[i] = 1;
		for (int j = i-1; j>=0; j--)
		{
			if(arr[j] < arr[i]){
				int length= inc[j] + 1;
                inc[i] = max(inc[i], length);
			}
		}
	}
	for (int i = size-2; i >=0; i--)
	{
        dec[i] = 1;
		for (int j = i+1; j< size; j++)
		{
			if(arr[j] < arr[i]){
				int length = dec[j] + 1;
                dec[i] = max(dec[i] , length);
			}
		}
	}

	int ans = inc[0] + dec[0] - 1;
	for (int i = 1; i < size; ++i)
	{
      //  cout << "inc :" << inc[i] << endl;
     //  cout << "dec :" << dec[i] << endl;
		int c = inc[i] + dec[i] - 1;
		ans = max(ans,c);
	}
	delete[] dec;
	delete[] inc;
	return ans;
     	
}

int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}
