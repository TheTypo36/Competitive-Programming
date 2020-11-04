#include <bits/stdc++.h>
using namespace std;
int query(int* tree, int start, int end, int treeNode, int left, int right){
	if(start > right || end < left){
		return 0;
	}
	if(start>=left && end <=right){
		return tree[treeNode];
	}
	int mid = (start + end)/2;
	int ans = query(tree,start,mid,2*treeNode,left,right);
	int ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);
	if(ans<ans2){
		return ans;
	}else{
		return ans2;
	}
}
void update(int* arr, int* tree, int start, int end, int treeNode, int idx, int value){
	if(start == end){
		arr[idx] = value;
		tree[treeNode] = value;
		return ;
	}
	int mid = (start + end)/2;
	if(idx > mid){
		update(arr,tree,mid+1,end,2*treeNode + 1, idx, value);
	}else{
		update(arr, tree, start, mid, 2*treeNode, idx, value);
	}

	if(tree[treeNode*2]<tree[2*treeNode + 1]){
		tree[treeNode] = tree[2*treeNode];
	}else{
		tree[treeNode] = tree[2*treeNode+1];

	}
}
void buildTree(int* arr, int* tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end)/2;
	buildTree(arr, tree, start, mid, 2*treeNode);
	buildTree(arr, tree,mid+1,end, 2*treeNode + 1);
	if(tree[treeNode*2]<tree[2*treeNode + 1]){
		tree[treeNode] = tree[2*treeNode];
	}else{
		tree[treeNode] = tree[2*treeNode+1];

	}
}
int main(){
	int n, q;
	cin >> n >> q;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int* tree = new int[4*n];
	buildTree(arr,tree,0,n-1,1);
	while(q--){
		char qu;
		cin >> qu;
		if(qu=='q'){
			int l, r;
			cin >> l >> r;
			cout << query(tree, 0, n-1, 1, l-1, r-1);
		}else if(qu == 'u'){
			int x,y;
			cin >> x >> y;
			update(arr,tree,0,n-1,1,x,y);
		}
	}
	return 0;
}