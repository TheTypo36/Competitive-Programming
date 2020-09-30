#include <bits/stdc++.h>
using namespace std;

int partition(int* arr, int si, int ei)
{
	int k = arr[si];
	int c = 0;
	for (int i = si+1; i <=ei; ++i)
	{
		if(arr[i] < k)
			c++;
	}
	int temp = arr[si+c];
	arr[si+c] = k;
	arr[si] = temp;
	int i = si;
	int j = si+c+1;
	while(i < si+c && j <= ei){
		if(arr[i]<= k){
			i++;
			continue;
		}
		if(arr[j] > k){
			j++;
			continue;
		}
		int swap = arr[j];
		arr[j] = arr[i];
		arr[i] = swap;
		i++;
		j++;
	}
}
void quickSort(int * arr , int si , int ei){
	if(si>=ei)
	{
		return;
	}
	int c = partition(arr,si , ei);
	quickSort(arr,si,c-1);
	quickSort(arr,c+1,ei);
}
int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i] ;
	}
	quickSort(arr,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
}