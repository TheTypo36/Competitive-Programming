#include <bits/stdc++.h>
using namespace std;

void merge2sortedArray(int* arr, int start, int mid , int end)
{
	int i= start;
	int j = mid;
	int temp[end - start + 1];
	int k = 0;
	while( i < mid && j <= end){
		if(arr[i] < arr[j]){
			temp[k++] = arr[i++];
		}else{
			temp[k++] = arr[j++];
		}
	}
	while( i < mid){
		temp[k++] = arr[i++];
	}
	while( j <= end){
		temp[k++] = arr[j++];
	}
	for (int i = start, k = 0; i <= end; ++i, k++)
	{
		arr[i] = temp[k];
	}
}
void merge_sort(int* arr, int low, int high)
{
	if(low >= high){
		return;
	}
	int mid = (low + high) / 2;
	merge_sort(arr,low , mid);
	merge_sort(arr,mid+1, high);

	merge2sortedArray(arr,low,mid+1,high);


}
int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	merge_sort(arr,0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
}