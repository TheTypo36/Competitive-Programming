#include <bits/stdc++.h>
using namespace std;
int query(int* tree, int* Lazy,int* arr, int start, int end,  int l, int r,int treeNode){
	if(Lazy[treeNode] != 0){
		tree[treeNode] += Lazy[treeNode];
		if(start != end){
			Lazy[2*treeNode] += Lazy[treeNode];
			Lazy[2*treeNode+1] += Lazy[treeNode];
		} 
		Lazy[treeNode] = 0;
	}
	if(start == end){
		return arr[start];
	}
	if(l > end || r < start){
		return INT_MAX;
	}
	if(l >= start && r <= end){
		return tree[treeNode];
	}
	int mid = (start + end)/2;
	int leftans = query(tree,Lazy,arr, start, mid, 2*treeNode,l,r);
	int rightans = query(tree,Lazy,arr, mid+1,end, 2*treeNode+1,l,r);
	return min(leftans, rightans);
}
void buildTree(int* arr, int * tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end)/2;
	buildTree(arr, tree, start , mid , 2* treeNode);
	buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1 );
	tree[treeNode] = min(tree[2*treeNode] , tree[2*treeNode + 1]);
}
void updateLazySegTree(int * tree,int * Lazy, int start, int end, int leftInterval, int rightInterval, int treeNode, int inc){
	if(start > end){
		return;
	}
	if(Lazy[treeNode]!=0){
		tree[treeNode] += Lazy[treeNode];
		if(start != end){
			Lazy[2*treeNode] += Lazy[treeNode];
			Lazy[2*treeNode+1] += Lazy[treeNode];

		}
		Lazy[treeNode] = 0;
	}
	if(leftInterval > end || rightInterval < start ){
		return;
	}
	if(leftInterval <= start && rightInterval >= end){
		tree[treeNode] += inc;
		if(start != end){
			Lazy[2*treeNode] += inc;
			Lazy[2*treeNode+1] += inc;
		}
		return;
	}
	int mid = (start + end)/2;
	updateLazySegTree(tree, Lazy, start, mid, leftInterval, rightInterval, 2*treeNode, inc);
	updateLazySegTree(tree, Lazy, mid+1, end, leftInterval, rightInterval, 2*treeNode+1, inc);
	tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode + 1]);
}
int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int* tree =new int [4*n]();
	int* Lazy = new int[4*n]();
	buildTree(arr,tree,0,n-1,1);

	  int q;
	  cin >> q;
	while(q--)
	{
	 	int r, l, inc;
		cin >> l >> r >> inc;
		updateLazySegTree(tree,Lazy,0,n-1,l-1,r-1,1, inc);
	 }
	 int quer;
	 cin >> quer;
	 while(quer--){
	 	int l , r;
	 	cin >> l >> r;
	 	int minAns = query(tree,Lazy,arr,0,n-1,l-1,r-1,1);
	 	cout << minAns << endl;
	 }
	delete[] arr;
	delete[] tree;
}