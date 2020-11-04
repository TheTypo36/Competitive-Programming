#include <bits/stdc++.h>
using namespace std;
void buildTree(int* arr, int* tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode]=arr[start];
		return;
	}
	int mid = (start + end)/2;
	buildTree(arr, tree, start, mid, 2 * treeNode);
	buildTree(arr, tree, mid+1, end, 2 * treeNode + 1);
	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}
void update(int* arr, int * tree, int start, int end, int treeNode, int idx, int value){
	if(start == end ){
		arr[idx] = value;
		tree[treeNode] = value;
		return;
	}
	int mid = (start + end) /2 ;
	if(idx > mid){
		update(arr,tree,mid+1,end, 2*treeNode+1,idx,value);
	}else{
		update(arr,tree,start,mid,2*treeNode,idx,value);
	}
	tree[treeNode] = tree[2 * treeNode] + tree[2* treeNode + 1];
}
int query(int* tree, int start, int end, int treeNode,int left, int right){

	//completely outside the range
	if(start>right || end < left){
		return 0;
	}

	//completely inside the range
	if(start>=left && end <=right){
		return tree[treeNode];
	}

	//partially inside and partially outside the range
	int mid = (start + end) /2;
	int ans1 = query(tree, start,mid,2*treeNode,left,right);
	int ans2 = query(tree, mid+1,end,2*treeNode+1,left,right);
	return ans2 + ans1;
}
int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int m = 2 * n;
	int* tree = new int[m];
	buildTree(arr, tree, 0, n-1, 1);
	update(arr,tree,0,n-1,1,2,10);
	for (int i = 1; i < m; ++i)
	{
		cout << tree[i] << endl;
	}
	cout << "The ans of the query is " << query(tree, 0, n-1, 1, 2,4);
}