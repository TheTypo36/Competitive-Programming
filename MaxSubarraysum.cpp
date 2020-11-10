#include <bits/stdc++.h>
using namespace std;
class Node{
public:
	int sum;
	int bps;
	int bss;
	int maxSum;
};

void build(int * arr, Node * tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode].maxSum = arr[start];
		tree[treeNode].sum =  arr[start];
		tree[treeNode].bps =  arr[start];
		tree [treeNode].bss =  arr[start];
		return;
	}
	int mid = (start + end)/2;
	build(arr, tree, start, mid, 2*treeNode);
	build(arr, tree, mid+1, end, 2*treeNode + 1);
	Node ls = tree[2*treeNode];
	Node rs = tree[2*treeNode + 1];
	Node final;
	final.sum = ls.sum + rs.sum;
	final.bps = max(ls.sum+rs.bps,ls.bps);
	final.bss = max(rs.sum+ls.bss,rs.bss);
	final.maxSum = max(max(max(ls.maxSum,rs.maxSum),max(ls.sum+rs.bps,rs.sum+ls.bss)),ls.bss+rs.bps);
	tree[treeNode] = final;
	return;
}
Node query(Node* tree , int start , int end,int treeNode, int left, int right){
	if(left > end || right < start){
		Node base;
		base.maxSum = -100000;
		base.bss = -100000;
		base.bps = -100000;
		base.sum = -100000;
		return base;
	}
	if(start >= left && end <= right){
		return tree[treeNode];
	}
	int mid = (start + end)/2;
	Node ls = query(tree, start, mid, 2 * treeNode, left, right);
	Node rs = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);
	Node final;
	final.sum = ls.sum + rs.sum;
	final.bps = max(ls.sum + rs.bps,ls.bps);
	final.bss = max(rs.sum + ls.bss,rs.bss);
	final.maxSum = max(max(max(ls.maxSum,rs.maxSum),max(ls.sum+rs.bps,rs.sum+ls.bss)),ls.bss+rs.bps);
	return final;
}
int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i = 0 ; i < n; i++){
		cin >> arr[i] ;
	}	
	Node* tree = new Node[4 * n];
	build(arr, tree, 0, n-1, 1);
	
	int q;
	cin >> q;
	while(q--){
		int xi, yi;
		cin >> xi >> yi;
		cout << query(tree,0,n-1,1,xi-1,yi-1).maxSum << endl;
	}
}