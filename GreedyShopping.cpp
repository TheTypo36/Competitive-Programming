#include <bits/stdc++.h>
using namespace std;

void update(int * arr, int * tree,int * lazy, int start, int end, int left ,int right , int value , int treeNode){
	if(start > end){
		return;
	
	}
	if(lazy[treeNode] != 0){
		tree[treeNode] += lazy[treeNode];
		if(start != end){
			lazy[2*treeNode] = lazy[treeNode]; 
			lazy[2*treeNode+1] = lazy[treeNode];
		}
		laz[treeNode] = 0;
	}
	if(left > end || right < start){
		return;
	}
	if(left >= start && right <= end){
		tree[treeNode] = max(tree[treeNode],y);
		if(start != end){
			lazy[2*treeNode] = tree[treeNode]; 
			lazy[2*treeNode+1] = tree[treeNode]; 
		}
		return;
	}
	int mid = (start + end)/2;
	update(arr, tree, lazy, start, mid, left, right, value, 2*treeNode);
	update(arr, tree, lazy, start, mid, left, right, value, 2*treeNode + 1);
	tree[treeNode] = max(tree[2*treeNode], tree[2*treeNode + 1]);


}
void buildTree(int * arr, int * tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
		return ;
	}
	int mid = (start + end)/2;
	buildTree(arr, tree, start, mid , treeNode*2);
	buildTree(arr, tree, mid +1, end, 1+(treeNode*2));
	tree[treeNode] = max(tree[treeNode*2],tree[2* treeNode + 1]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);


		int n;
		cin >>n;
		int q;
		cin >> q;	
		int* arr = new int[n];
		int* tree = new int[4*n];
		for(int i= 0 ; i < n; i++){
	         cin >> arr[i];
		}
		buildTree(arr, tree, 0, n -1, 1);
		while(q--)
		{
			int t, x, int y;
			cin >> t >> x >> y;
			if(t == 1){
				update(arr, tree,0,n-1, 0, x, y, 1);
			}else{

			}
		}
		  k
}