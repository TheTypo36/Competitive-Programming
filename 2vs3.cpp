#include <bits/stdc++.h>
using namespace std;

int power()
void buildTree(int* arr, int* tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);
	int a = 0;
	if(modrelation[end-mid]=-1){
		a = modrelation[end-mid];
	}else{
		a = pow(2,(end-mid))%3;
		modrelation[end-mid] = a;
	}
	tree[treeNode] = (tree[2*treeNode+1]+(a%3)%3);
	
}
int main(){

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	for (int i = 0; i < 100000; ++i)
	{
		modrelation[i] = -1;
	}
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i = 0 ; i < n; i++){
		cin >> arr[i];
	}
	int* tree = new int[4*n];
	buildTree(arr,tree,0,n-1,1);
	int q;
	cin >> q;
	while(q--){
		int option ;
		cin >> option;
		if(option == 0){
			int l , r;
			cin >> l >> r;

		}else{
			int index;
			int value;
			cin >> index >> value;
			
		}
	}
	delete[]tree;
	delete[]arr;
}