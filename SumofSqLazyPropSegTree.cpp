#include <bits/stdc++.h>
using namespace std;
int query(int* tree, int* lazy, int start, int end ,int left, int right, int treeNode){
	//read the problem statement than program for the query
	if(lazy[treeNode] != 0){
		tree[treeNode] += lazy[treeNode];
		if(start!=end){
			lazy[2*treeNode] = lazy[treeNode];
			lazy[2*treeNode+1] = lazy[treeNode];
		}
		lazy[treeNode] = 0;
	}
	if(start == end){
		return tree[treeNode];
	}
	if(left > end || right < start){
		return 0;
	}
	if(left>=start && right <= end){
		return tree[treeNode];
	}
	int mid = (start + end)/2;
	int leftans = query(tree,lazy,start,mid,left,right,2*treeNode);                                                                                
	int rightans = query(tree,lazy,mid+1,end,left,right,2*treeNode+1);                                                                                
	return leftans + rightans;

}
void updateLazy(int* tree, int * lazy, int start, int end, int left, int right, int treeNode, int value,int option){
	if(start > end){
		return;
	}
	if(lazy[treeNode]!=0){
		tree[treeNode] += lazy[treeNode];
		if(start!=end){
			lazy[2*treeNode] += lazy[treeNode];
			lazy[2*treeNode] += lazy[treeNode];
		}
		lazy[treeNode] = 0;
	}
	if(left > end|| right < start){
		return;
	}
	if(left >=start && right <=  end){
		if(option == 1){
			tree[treeNode] +=value;
			if(start != end){
				lazy[2*treeNode] += value;
				lazy[2*treeNode] +=value;
			}
		}else{
			tree[treeNode] = value;
			if(start != end){
				lazy[2*treeNode] = value;
				lazy[2*treeNode+1] = value;
			}
		}
	}
	int mid = (start + end)/2;
	updateLazy(tree,lazy,start,mid,left,right,2*treeNode, value,option);
	updateLazy(tree,lazy,mid+1,end,left,right,2*treeNode+1, value,option);

}
void buildtree(int* tree, int* arr, int start, int end , int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end)/2;
	buildtree(tree, arr, start, mid, 2* treeNode);
	buildtree(tree, arr, mid +1 ,end, 2* treeNode +1 );
	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int testcases;
	cin >> testcases;
	while(testcases--){
		int n, q;
		cin >> n >> q;
		int* arr = new int[n];
		for(int i = 0 ; i < n; i++){
			cin >> arr[i];
		}
		int* tree = new int[4*n]();
		int* lazy = new int[4*n]();
		buildtree(tree, arr, 0, n-1, 1);
		while(q--){
			int option;
			cin >> option;
			if(option == 0 || option == 1){
				int l , r , value;
				cin >> l >> r >> value;
				updateLazy(tree,lazy,0, n-1,  l-1,  r-1,  1,  value, option);
			}else{
				int l, r;
				cin >> l >> r;
				int ans = query(tree, lazy, 0, n-1,  l-1, r-1, 1);
				cout << ans << endl;
			}
		}
	}
}