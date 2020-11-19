#include <bits/stdc++.h>
using namespace std; 
class tree_att{
	public:
		int odd;
		int even;
		
};

tree_att query(tree_att * tree, int start, int end , int treeNode, int left , int right){
	if(left>end || right < start ){
		tree_att ans;
    	ans.odd = 0;
        ans.even = 0;

		return ans;

	}
	if(start >= left && end <= right){
		return tree[treeNode];
	}
	int mid = (start + end)/2;
	tree_att leftans = query(tree, start, mid, 2*treeNode, left, right);
	tree_att rightans = query(tree,  mid+1,end, 2*treeNode+1, left, right);
	tree_att ans;
	ans.odd = leftans.odd + rightans.odd;
	ans.even = leftans.even + rightans.even;
	return ans;
}
void update(tree_att* tree, int* arr, int start, int end , int treeNode, int index, int value){
	if(start == end){
		arr[index] = value;
		if(value%2!=0){
			tree[treeNode].odd = 1;
            tree[treeNode].even = 0;
		}else{
            tree[treeNode].odd = 0;
			tree[treeNode].even = 1;
		}
		return;
	}
	int mid = (start + end)/2;
	if(index > mid){

		update(tree,arr,mid+1,end,2*treeNode+1, index,value);
	}else{

		update(tree,arr,start,mid,2*treeNode, index,value);
	}
	tree[treeNode].odd = tree[2*treeNode].odd + tree[2*treeNode+1].odd;
	tree[treeNode].even = tree[2*treeNode].even + tree[2*treeNode+1].even;
}
void buildTree(tree_att* tree, int *arr, int start, int end , int treeNode){
	if(start == end){
		if(arr[start]%2!=0){
			tree[treeNode].odd = 1;
            tree[treeNode].even = 0;
		}else{
            tree[treeNode].odd = 0;
			tree[treeNode].even = 1;
		}
		return;
	}
	int mid = (start + end)/2;
	buildTree(tree, arr, start, mid, 2*treeNode);
	buildTree(tree, arr, mid+1, end, 2*treeNode+1);
	tree[treeNode].odd = tree[2*treeNode].odd + tree[2*treeNode+1].odd;
	tree[treeNode].even = tree[2*treeNode].even + tree[2*treeNode+1].even;
}
int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i = 0 ;i < n; i++){
		cin >> arr[i];
	}
	tree_att* tree = new tree_att[4*n]();
	buildTree(tree,arr, 0, n-1, 1);
	int q;
	cin >> q;   
	while(q--)
	{
		int option , x, y;
		cin >> option >> x >>y;
		if(option == 0){
			update(tree,arr,0,n-1,1,x-1,y);
		}else if(option == 1){
			cout << query(tree,0,n-1,x-1,y-1,1).even << endl;
		}else{
			cout << query(tree,0,n-1,x-1,y-1,1).odd << endl;
		}

	}
	delete []arr;
	delete[] tree;
}