#include <bits/stdc++.h>
using namespace std;

void buildTree(int* arr, int * tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end)/2;
	buildTree(arr, tree, 0 , mid , 2* treeNode);
	buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1 );
	tree[treeNode] = min(tree[2*treeNode] , tree[2*treeNode + 1]);
	return;
}
int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	int* tree =new int [4*n];

	buildTree(arr,tree,0,n-1,1);
	  int q;
	// while(q--){
	// 	int r, l;
	// 	cin >> l >> r;
	// }
	  for(int i = 0 ;i < n; i++){
	  	cout << tree[i] << endl;
	  }
	delete[] arr;
	delete[] tree;
}